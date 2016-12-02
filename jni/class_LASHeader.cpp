/*
 * class_LASHeader.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: jani
 */

#include "org_lastools_LASHeader.h"
#include "lasdefinitions.hpp"

/*
 * Class:     org_lastools_LASHeader
 * Method:    check
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_lastools_LASHeader_check(JNIEnv *env,
        jobject lasHeader) {
    PREAMBLE;
    LASheader* header = LOAD_LASHEADER_POINTER(lasHeader);
    return header->check();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASHeader
 * Method:    isCompressed
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_lastools_LASHeader_isCompressed(JNIEnv *env,
        jobject lasHeader) {
    PREAMBLE;
    LASheader* header = LOAD_LASHEADER_POINTER(lasHeader);
    return header->is_compressed();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASHeader
 * Method:    isLonLat
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_lastools_LASHeader_isLonLat(JNIEnv *env,
        jobject lasHeader) {
    PREAMBLE;
    LASheader* header = LOAD_LASHEADER_POINTER(lasHeader);
    return header->is_lonlat();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASHeader
 * Method:    dealloc
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_lastools_LASHeader_dealloc
(JNIEnv *env, jobject, jlong ptr) {
    PREAMBLE;
    LASheader* header = static_cast<LASheader*>(TO_POINTER(ptr));
    if (header) {
        delete header;
    }
    TRAILER_VOID;
}

