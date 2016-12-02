package org.lastools;

import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.atomic.AtomicInteger;

public class LASlibJNI {

    private static boolean initialized;
    private static boolean initializationFailure;

    private static final Map<Class<? extends NativeObject>, AtomicInteger> nativeAllocCounts;
    static {
        nativeAllocCounts = new HashMap<>();
        nativeAllocCounts.put(LASReader.class, new AtomicInteger());
        nativeAllocCounts.put(LASHeader.class, new AtomicInteger());
        nativeAllocCounts.put(LASPoint.class, new AtomicInteger());
    }

    public synchronized static void initialize(String libPath) {
        if (!initialized) {
            if (initializationFailure) {
                throw new IllegalStateException("Previous call to LASlibJNI.initialize() failed");
            }
            System.load(libPath);

            try {
                nativeInit();
                initialized = true;
            } finally {
                if (!initialized) {
                    initializationFailure = true;
                }
            }
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
