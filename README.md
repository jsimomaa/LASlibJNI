# LASlibJNI 

JNI for LASlib C++ library

## How to use

    LASlibJNI.initialize(LIB_FILE);
    
    try (LASReader reader = new LASReader("/path/to/my_las_file.las")) {
        while (reader.readPoint()) {
            LASPoint point = reader.getPoint();
            
            int x = point.getX();
            int y = point.getY();
            int z = point.getZ();
            System.out.println(x + y + z);
        }
    }