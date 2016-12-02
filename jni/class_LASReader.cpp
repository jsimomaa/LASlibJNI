/*
 * class_LASReader.c
 *
 *  Created on: Dec 1, 2016
 *      Author: jani
 */
#include <stdio.h>

#include "org_lastools_LASReader.h"
#include "lasreader.hpp"

JNIEXPORT jlong JNICALL Java_org_lastools_LASReader_alloc(JNIEnv *env, jclass c,
        jstring lasFile) {
    PREAMBLE;

    refjavastring filename(env, lasFile);

    LASreadOpener lasreadopener;
    lasreadopener.set_file_name(filename.stringz);
    LASreader* lasreader = lasreadopener.open();

    return FROM_POINTER(lasreader);
    TRAILER(0);
}

JNIEXPORT void JNICALL Java_org_lastools_LASReader_dealloc
(JNIEnv *env, jobject, jlong ptr) {
    PREAMBLE;
    LASreader* reader = static_cast<LASreader*>(TO_POINTER(ptr));
    if (reader) {
        reader->close();
        delete reader;
    }
    TRAILER_VOID;
}

/*
 * Class:     org_lastools_LASReader
 * Method:    getHeader
 * Signature: ()Lorg/lastools/LASHeader;
 */
JNIEXPORT jobject JNICALL Java_org_lastools_LASReader_getHeader
  (JNIEnv *env, jobject readerObj) {
    PREAMBLE;
    LASreader* reader = LOAD_LASREADER_POINTER(readerObj);

    jobject header = env->NewObject(CLASS_LASHEADER, CTOR_NATIVEOBJECT);
    env->SetLongField(header, FIELD_PTR, FROM_POINTER(&reader->header));
    return header;
    TRAILER(0);
}


/*
 * Class:     org_lastools_LASReader
 * Method:    readPoint
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_lastools_LASReader_readPoint(JNIEnv *env,
        jobject readerObj) {
    PREAMBLE;
    LASreader* reader = LOAD_LASREADER_POINTER(readerObj);
    return reader->read_point();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASReader
 * Method:    getPoint
 * Signature: ()Lorg/lastools/LASPoint;
 */
JNIEXPORT jobject JNICALL Java_org_lastools_LASReader_getPoint(JNIEnv *env,
        jobject readerObj) {
    PREAMBLE;
    LASreader* reader = LOAD_LASREADER_POINTER(readerObj);

    jobject point = env->NewObject(CLASS_LASPOINT, CTOR_NATIVEOBJECT);
    env->SetLongField(point, FIELD_PTR, FROM_POINTER(&reader->point));
    return point;
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASReader
 * Method:    getMinX
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_org_lastools_LASReader_getMinX(JNIEnv *env,
        jobject readerObj) {
    PREAMBLE;
    LASreader* reader = LOAD_LASREADER_POINTER(readerObj);
    return reader->get_min_x();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASReader
 * Method:    getMinY
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_org_lastools_LASReader_getMinY(JNIEnv *env,
        jobject readerObj) {
    PREAMBLE;
    LASreader* reader = LOAD_LASREADER_POINTER(readerObj);
    return reader->get_min_y();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASReader
 * Method:    getMinZ
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_org_lastools_LASReader_getMinZ(JNIEnv *env,
        jobject readerObj) {
    PREAMBLE;
    LASreader* reader = LOAD_LASREADER_POINTER(readerObj);
    return reader->get_min_z();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASReader
 * Method:    getMaxX
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_org_lastools_LASReader_getMaxX(JNIEnv *env,
        jobject readerObj) {
    PREAMBLE;
    LASreader* reader = LOAD_LASREADER_POINTER(readerObj);
    return reader->get_max_x();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASReader
 * Method:    getMaxY
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_org_lastools_LASReader_getMaxY(JNIEnv *env,
        jobject readerObj) {
    PREAMBLE;
    LASreader* reader = LOAD_LASREADER_POINTER(readerObj);
    return reader->get_max_y();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASReader
 * Method:    getMaxZ
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_org_lastools_LASReader_getMaxZ(JNIEnv *env,
        jobject readerObj) {
    PREAMBLE;
    LASreader* reader = LOAD_LASREADER_POINTER(readerObj);
    return reader->get_max_z();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASReader
 * Method:    getX
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_org_lastools_LASReader_getX(JNIEnv *env,
        jobject readerObj) {
    PREAMBLE;
    LASreader* reader = LOAD_LASREADER_POINTER(readerObj);
    return reader->get_x();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASReader
 * Method:    getY
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_org_lastools_LASReader_getY(JNIEnv *env,
        jobject readerObj) {
    PREAMBLE;
    LASreader* reader = LOAD_LASREADER_POINTER(readerObj);
    return reader->get_y();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASReader
 * Method:    getZ
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_org_lastools_LASReader_getZ(JNIEnv *env,
        jobject readerObj) {
    PREAMBLE;
    LASreader* reader = LOAD_LASREADER_POINTER(readerObj);
    return reader->get_z();
    TRAILER(0);
}

