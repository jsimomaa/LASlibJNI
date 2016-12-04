package org.lastools;

public class LASPoint extends NativeObject {

    public native boolean isFirst();

    public native boolean isIntermediate();

    public native boolean isLast();

    public native boolean isSingle();

    public native boolean isFirstOfMany();

    public native boolean isLastOfMany();

    public native double getX();

    public native double getY();

    public native double getZ();

    public native int getIntensity();

    public native char getReturnNumber();

    public native char getNumberOfReturns();

    public native char getScanDirectionFlag();

    public native char getEdgeOfFlightLine();

    public native char getClassification();

    public native char getSyntheticFlag();

    public native char getKeypointFlag();

    public native char getWithheldFlag();

    public native char getScanAngleRank();

    public native char getUserData();

    public native int getPointSourceId();

    public native int getDeletedFlag();

    public native double getGPSTime();

//    public native int getRGB();

    public native int getR();

    public native int getG();

    public native int getB();

    public native int getI();

    public native int getNIR();
    
    private static native long alloc();

    @Override
    native void dealloc(long ptr);

}
