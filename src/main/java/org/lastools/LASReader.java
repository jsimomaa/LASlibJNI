package org.lastools;

public class LASReader extends NativeObject {

    private static native long alloc(String lasFile);

    native void dealloc(long ptr);

    public LASReader(String lasFile) {
        ptr = alloc(lasFile);
    }

    public native LASHeader getHeader();

    public native boolean readPoint();

    public native LASPoint getPoint();

    public native double getMinX();

    public native double getMinY();

    public native double getMinZ();

    public native double getMaxX();

    public native double getMaxY();

    public native double getMaxZ();

    public native double getX();

    public native double getY();

    public native double getZ();

}
