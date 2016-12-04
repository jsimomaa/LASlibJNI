package org.lastools;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.URL;
import java.nio.file.DirectoryStream;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.attribute.PosixFilePermission;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Properties;
import java.util.Set;
import java.util.UUID;
import java.util.concurrent.atomic.AtomicInteger;

import org.lastools.util.OSInfo;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * @author Jani Simomaa
 *
 */
public class LASlibJNI {

    private static final Logger LOGGER = LoggerFactory.getLogger(LASlibJNI.class);

    private static boolean extracted;

    private static final Map<Class<? extends NativeObject>, AtomicInteger> nativeAllocCounts;
    static {
        nativeAllocCounts = new HashMap<>();
        nativeAllocCounts.put(LASReader.class, new AtomicInteger());
        nativeAllocCounts.put(LASHeader.class, new AtomicInteger());
        nativeAllocCounts.put(LASPoint.class, new AtomicInteger());
    }

    /**
     * Initialize LASlibJNI with bundled dll/so library
     * 
     * @throws Exception
     */
    public synchronized static void initialize() throws Exception {
        // only cleanup before the first extract
        if (extracted) {
            return;
        }
        cleanup();
        
        // Try loading library from org.lastools.LASlibJNI.lib.path library path
        // */
        String lasLibJNINativeLibraryPath = System.getProperty("org.lastools.LASlibJNI.lib.path");

        if (lasLibJNINativeLibraryPath != null) {
            Path libPath = Paths.get(lasLibJNINativeLibraryPath);
            if (!Files.exists(libPath)) {
                LOGGER.info(lasLibJNINativeLibraryPath + " is not found!");
            } else {
                if (loadNativeLibrary(libPath.getParent(), libPath.getFileName().toString())) {
                    extracted = true;
                    return;
                }
            }
        }

        // Load the os-dependent library from the jar file
        lasLibJNINativeLibraryPath = "/lib/" + OSInfo.getNativeLibFolderPathForCurrentOS();
        String libName = System.mapLibraryName("LASlibJNI");
        boolean hasNativeLib = hasResource(lasLibJNINativeLibraryPath);

        if (!hasNativeLib) {
            extracted = false;
            throw new Exception(String.format("No native library is found for os.name=%s and os.arch=%s",
                    OSInfo.getOSName(), OSInfo.getArchName()));
        }

        // temporary library folder
        Path tempFolder = Paths.get(System.getProperty("java.io.tmpdir"));
        // Try extracting the library from jar
        if (extractAndLoadLibraryFile(lasLibJNINativeLibraryPath, libName, tempFolder)) {
            extracted = true;
            return;
        }

        extracted = false;
        return;
    }

    /**
     * Extracts and loads the specified library file to the target folder
     *
     * @param libFolderForCurrentOS
     *            Library path.
     * @param libraryFileName
     *            Library name.
     * @param tempFolder
     *            Target folder.
     * @return
     */
    private static boolean extractAndLoadLibraryFile(String libFolderForCurrentOS, String libraryFileName,
            Path tempFolder) {
        String nativeLibraryFilePath = libFolderForCurrentOS + "/" + libraryFileName;
        // Include architecture name in temporary filename in order to avoid
        // conflicts
        // when multiple JVMs with different architectures running at the same
        // time
        String uuid = UUID.randomUUID().toString();
        String extractedLibFileName = String.format("LASlibJNI-%s-%s-%s", getVersion(), uuid, libraryFileName);
        String extractedLckFileName = extractedLibFileName + ".lck";

        Path extractedLibFile = tempFolder.resolve(extractedLibFileName);
        Path extractedLckFile = tempFolder.resolve(extractedLckFileName);

        try {
            // Extract a native library file into the target directory
            InputStream reader = LASlibJNI.class.getResourceAsStream(nativeLibraryFilePath);

            OutputStream writer = Files.newOutputStream(extractedLibFile);
            try {
                byte[] buffer = new byte[8192];
                int bytesRead = 0;
                while ((bytesRead = reader.read(buffer)) != -1) {
                    writer.write(buffer, 0, bytesRead);
                }
            } finally {
                if (!Files.exists(extractedLckFile))
                    Files.newOutputStream(extractedLckFile).close();

                // Delete the extracted lib file on JVM exit.
                extractedLibFile.toFile().deleteOnExit();
                extractedLckFile.toFile().deleteOnExit();

                if (writer != null) {
                    writer.close();
                }
                if (reader != null) {
                    reader.close();
                }
            }

            boolean isPosix = FileSystems.getDefault().supportedFileAttributeViews().contains("posix");
            if (isPosix) {
                // Set executable (x) flag to enable Java to load the native library
                Set<PosixFilePermission> perms = new HashSet<PosixFilePermission>();
                // add owners permission
                perms.add(PosixFilePermission.OWNER_READ);
                perms.add(PosixFilePermission.OWNER_WRITE);
                perms.add(PosixFilePermission.OWNER_EXECUTE);
                // add group permissions
                perms.add(PosixFilePermission.GROUP_READ);
                perms.add(PosixFilePermission.GROUP_WRITE);
                perms.add(PosixFilePermission.GROUP_EXECUTE);
                // add others permissions
                perms.add(PosixFilePermission.OTHERS_READ);
                perms.add(PosixFilePermission.OTHERS_WRITE);
                perms.add(PosixFilePermission.OTHERS_EXECUTE);
                Files.setPosixFilePermissions(extractedLibFile, perms);
            }

            // Check whether the contents are properly copied from the resource
            // folder
            {
                InputStream nativeIn = LASlibJNI.class.getResourceAsStream(nativeLibraryFilePath);
                InputStream extractedLibIn = Files.newInputStream(extractedLibFile);
                try {
                    if (!contentsEquals(nativeIn, extractedLibIn)) {
                        throw new RuntimeException(
                                String.format("Failed to write a native library file at %s", extractedLibFile));
                    }
                } finally {
                    if (nativeIn != null) {
                        nativeIn.close();
                    }
                    if (extractedLibIn != null) {
                        extractedLibIn.close();
                    }
                }
            }
            return loadNativeLibrary(tempFolder, extractedLibFileName);
        } catch (IOException e) {
            LOGGER.error("Could not extract and load native library", e);
            return false;
        }
    }

    private static boolean contentsEquals(InputStream in1, InputStream in2) throws IOException {
        if (!(in1 instanceof BufferedInputStream)) {
            in1 = new BufferedInputStream(in1);
        }
        if (!(in2 instanceof BufferedInputStream)) {
            in2 = new BufferedInputStream(in2);
        }

        int ch = in1.read();
        while (ch != -1) {
            int ch2 = in2.read();
            if (ch != ch2) {
                return false;
            }
            ch = in1.read();
        }
        int ch2 = in2.read();
        return ch2 == -1;
    }

    /**
     * Loads native library using the given path and name of the library.
     * 
     * @param tempFolder
     *
     * @param path
     *            Path of the native library.
     * @return True for successfully loading; false otherwise.
     */
    private static synchronized boolean loadNativeLibrary(Path tempFolder, String path) {
        Path libPath = tempFolder.resolve(path);
        if (Files.exists(libPath)) {
            try {
                System.load(libPath.toAbsolutePath().toString());
                nativeInit();
                return true;
            } catch (UnsatisfiedLinkError e) {
                System.err.println("Failed to load native library:" + path + ". osinfo: "
                        + OSInfo.getNativeLibFolderPathForCurrentOS());
                System.err.println(e);
                return false;
            }
        } else {
            return false;
        }
    }

    private static boolean hasResource(String path) {
        return LASlibJNI.class.getResource(path) != null;
    }

    /**
     * @return The version of the LASlibJNI driver.
     */
    public static String getVersion() {

        URL versionFile = LASlibJNI.class.getResource("/META-INF/maven/org.lastools/LASlibJNI/pom.properties");
        if (versionFile == null)
            versionFile = LASlibJNI.class.getResource("/META-INF/maven/org.lastools/LASlibJNI/VERSION");

        String version = "unknown";
        try {
            if (versionFile != null) {
                Properties versionData = new Properties();
                versionData.load(versionFile.openStream());
                version = versionData.getProperty("version", version);
                version = version.trim().replaceAll("[^0-9\\.]", "");
            }
        } catch (IOException e) {
            LOGGER.error("Could not get version", e);
        }
        return version;
    }

    /**
     * Deleted old native libraries e.g. on Windows the DLL file is not removed
     * on VM-Exit (bug #80)
     */
    static void cleanup() {
        Path tmp = Paths.get(System.getProperty("java.io.tmpdir"));

        try (DirectoryStream<Path> stream = Files.newDirectoryStream(tmp, "LASlibJNI-" + getVersion())) {
            for (Path path : stream) {
                if (!path.endsWith(".lck")) {
                    Path lockFile = Paths.get(path.toAbsolutePath().toString() + ".lck");
                    if (!Files.exists(lockFile)) {
                        Files.delete(path);
                    }
                }
            }
        } catch (IOException e) {
            LOGGER.error("Couldn't do cleanup for old libraries!", e);
        }
    }

    private static native void nativeInit();

    static void incrementAlloc(Class<? extends NativeObject> clazz, int delta) {
        AtomicInteger i = nativeAllocCounts.get(clazz);
        if (i == null)
            throw new IllegalStateException("Not allocation counter defined for " + clazz.getName());
        i.addAndGet(delta);
    }
}
