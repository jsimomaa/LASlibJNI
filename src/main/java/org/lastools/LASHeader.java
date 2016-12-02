package org.lastools;

public class LASHeader extends NativeObject {

    public native boolean check();

    public native boolean isCompressed();

    public native boolean isLonLat();

    @Override
    native void dealloc(long ptr);

}
