# LASlibJNI 

Java Native Interface (JNI) bindings based on [LAStools/LASlib](https://github.com/LAStools/LAStools/tree/master/LASlib) C++ API for reading/writing LIDAR data stored in standard LAS or in compressed LAZ format (versions 1.0 - 1.3).

## Bundled prebuilt libraries

LASlibJNI comes bundled with prebuilt libraries for [`Windows 64bit` and `Linux 64bit`](https://github.com/jsimomaa/LASlibJNI/tree/master/src/main/resources/lib)

## Build from source

To build `LASlibJNI` from source, run:

    git clone https://github.com/jsimomaa/LASlibJNI.git
    cd LASlibJNI
    mvn install
    
You can find the built JAR from `LASlibJNI/target/LASlibJNI-${version}.jar`

## How to use

    import org.lastools.LASHeader;
    import org.lastools.LASPoint;
    import org.lastools.LASReader;
    import org.lastools.LASlibJNI;

    public static void main(String [] args) {
        // Initialize the native library
        LASlibJNI.initialize();
        
        // Get an instance of LASReader for provided file
        try (LASReader reader = new LASReader("src/test/resources/1.0_0.las")) {
        
            // Get the header information of the file
            LASheader header = reader.getHeader();
            
            // Check that the file is supported and in tact
            if (header.check()) {
                // Ok, read points
                while (reader.readPoint()) {
                    LASPoint point = reader.getPoint();
                    double x = point.getX();
                    double y = point.getY();
                    double z = point.getZ();
                    System.out.println(x + y + z);
                }
            }
        }
    }
    
## Notes

* Currently supports only **reading** of files
