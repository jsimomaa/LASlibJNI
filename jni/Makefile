# define JDK include folder
JAVA_INCLUDE = /usr/lib/jvm/java-8-openjdk-amd64/include
JAVA_INCLUDE_LINUX = /usr/lib/jvm/java-8-openjdk-amd64/include/linux
LASZIP_INC = /home/jani/git/LAStools/LASzip/src
LASLIB_INC = /home/jani/git/LAStools/LASlib/inc

# Define a variable for classpath
CLASS_PATH = ../target/classes

# Define a virtual path for .class in the bin directory
vpath %.class $(CLASS_PATH)

# $@ matches the target, $< matches the first dependancy
LASlibJNI.so : LASlibJNI.o
	g++ -shared -fPIC -g -o $@ $< -L. -llas

# $@ matches the target, $< matches the first dependancy
LASlibJNI.o : LASlibJNI.cpp LASlibJNI.h
	g++ -I $(JAVA_INCLUDE) -I $(JAVA_INCLUDE_LINUX) -I $(LASZIP_INC) -I $(LASLIB_INC) -g -Wall -fPIC -c $< -o $@ -llas

# $* matches the target filename without the extension
LASlibJNI.h :
	javah -classpath $(CLASS_PATH) -jni org.lastools.LASlibJNI org.lastools.LASReader org.lastools.LASPoint org.lastools.LASHeader

clean :
	rm org_lastools_LASlibJNI.h