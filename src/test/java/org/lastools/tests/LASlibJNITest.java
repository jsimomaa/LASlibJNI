package org.lastools.tests;

import org.junit.Test;
import org.lastools.LASHeader;
import org.lastools.LASPoint;
import org.lastools.LASReader;
import org.lastools.LASlibJNI;

public class LASlibJNITest {

    @Test
    public void loadLibraryTest() throws Exception {
        LASlibJNI.initialize();
    }

    @Test
    public void readSampleLAS() throws Exception {
        LASlibJNI.initialize();

        try (LASReader reader = new LASReader("src/test/resources/1.0_0.las")) {
            while (reader.readPoint()) {
                LASPoint point = reader.getPoint();

                double x = point.getX();
                double y = point.getY();
                double z = point.getZ();

                System.out.println(x + y + z);
            }
        }
    }

    @Test
    public void readLASHeader() throws Exception {

        LASlibJNI.initialize();

        try (LASReader reader = new LASReader("src/test/resources/1.0_0.las")) {
            LASHeader header = reader.getHeader();

            boolean compressed = header.isCompressed();

            System.out.println(compressed);
        }
    }
}
