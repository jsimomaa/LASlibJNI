package org.lastools.tests;

import org.junit.Test;
import org.lastools.LASHeader;
import org.lastools.LASPoint;
import org.lastools.LASReader;
import org.lastools.LASlibJNI;

public class LASlibJNITest {

    private static final String LIB_FILE = "/home/jani/workspaces/LASlibJava/LASlib4j/jni/LASlibJNI.so";
    
    @Test
    public void loadLibraryTest() {
        LASlibJNI.initialize(LIB_FILE);
    }
    
    @Test
    public void readSampleLAS() {
        LASlibJNI.initialize(LIB_FILE);
        
        try (LASReader reader = new LASReader("/home/jani/workspaces/LASlibJava/LASlib4j/src/test/resources/1.0_0.las")) {
            while (reader.readPoint()) {
                LASPoint point = reader.getPoint();
                
                int x = point.getX();
                int y = point.getY();
                int z = point.getZ();
                System.out.println(x + y + z);
            }
        }
    }
    
    @Test
    public void readLASHeader() {
        
        LASlibJNI.initialize(LIB_FILE);
        
        try (LASReader reader = new LASReader("/home/jani/workspaces/LASlibJava/LASlib4j/src/test/resources/1.0_0.las")) {
            LASHeader header = reader.getHeader();
            
            boolean compressed = header.isCompressed();
            
            System.out.println(compressed);
        }
    }
}
