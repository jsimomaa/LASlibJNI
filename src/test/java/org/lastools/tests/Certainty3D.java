package org.lastools.tests;

import org.junit.Assert;
import org.junit.Test;
import org.lastools.LASPoint;
import org.lastools.LASReader;
import org.lastools.LASlibJNI;

public class Certainty3D {

    
    @Test
    public void certainty3D() throws Exception {
        LASlibJNI.initialize();
        
        int pointCount = 0;
        double minX = Double.MAX_VALUE, minY = Double.MAX_VALUE, minZ = Double.MAX_VALUE;
        double maxX = Double.MIN_VALUE, maxY = Double.MIN_VALUE, maxZ = Double.MIN_VALUE;
        
        int maxRed = Integer.MIN_VALUE;
        int maxGreen = Integer.MIN_VALUE;
        int maxBlue = Integer.MIN_VALUE;
        
        int minRed = Integer.MAX_VALUE;
        int minGreen = Integer.MAX_VALUE;
        int minBlue = Integer.MAX_VALUE;
        
        try (LASReader reader = new LASReader("src/test/resources/certainty3d-color-utm-feet-navd88.las")) {
            while (reader.readPoint()) {
                LASPoint point = reader.getPoint();
                
                double x = point.getX();
                double y = point.getY();
                double z = point.getZ();
                
                maxX = assignGreater(x, maxX);
                maxY = assignGreater(y, maxY);
                maxZ = assignGreater(z, maxZ);
                minX = assignLesser(x, minX);
                minY = assignLesser(y, minY);
                minZ = assignLesser(z, minZ);
                
                int R = point.getR();
                int G = point.getG();
                int B = point.getB();
                
                maxRed = assignGreater(R, maxRed);
                maxGreen = assignGreater(G, maxGreen);
                maxBlue = assignGreater(B, maxBlue);
                minRed = assignLesser(R, minRed);
                minGreen = assignLesser(G, minGreen);
                minBlue = assignLesser(B, minBlue);
                
                pointCount++;
            }
        }
        Assert.assertEquals(10126, pointCount);
        
        Assert.assertEquals(6326726.536120, minX, 0.000001);
        Assert.assertEquals(2068062.385430, minY, 0.000001);
        Assert.assertEquals(2700.5303501, minZ, 0.000001);
        Assert.assertEquals(6330162.951062, maxX, 0.000001);
        Assert.assertEquals(2071932.240223, maxY, 0.000001);
        Assert.assertEquals(2975.7118862, maxZ, 0.000001);
        
        Assert.assertEquals(4096, minRed);
        Assert.assertEquals(2304, minGreen);
        Assert.assertEquals(0, minBlue);
        
        Assert.assertEquals(65280, maxRed);
        Assert.assertEquals(64512, maxGreen);
        Assert.assertEquals(56320, maxBlue);
    }
    
    private static double assignLesser(double value, double current) {
        if (value < current)
            current = value;
        return current;
    }
    
    private static double assignGreater(double value, double current) {
        if (value > current)
            current = value;
        return current;
    }
    
    private static int assignLesser(int value, int current) {
        if (value < current)
            current = value;
        return current;
    }
    
    private static int assignGreater(int value, int current) {
        if (value > current)
            current = value;
        return current;
    }
}
