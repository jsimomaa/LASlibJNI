package org.lastools.tests;

import static org.junit.Assert.assertEquals;

import org.junit.Test;
import org.lastools.LASHeader;
import org.lastools.LASReader;
import org.lastools.LASlibJNI;

public class LAZReaderTest {

    @Test
    public void readLAZ() throws Exception {
        LASlibJNI.initialize();
        
        try (LASReader reader = new LASReader("src/test/resources/1.2-with-color.laz")) {
            LASHeader header = reader.getHeader();
            
            assertEquals(true, header.isCompressed());
        }
    }
}
