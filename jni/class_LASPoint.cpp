/*
 * class_LASPoint.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: jani
 */

#include "org_lastools_LASPoint.h"
#include "laspoint.hpp"

/*
 * Class:     org_lastools_LASPoint
 * Method:    alloc
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_lastools_LASPoint_alloc
  (JNIEnv *env, jclass c) {
    PREAMBLE;
    return FROM_POINTER(new LASpoint());
    TRAILER(0);
}


/* Class:     org_lastools_LASPoint
 * Method:    isFirst
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_lastools_LASPoint_isFirst(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->is_first();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    isIntermediate
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_lastools_LASPoint_isIntermediate(
        JNIEnv *env, jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->is_intermediate();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    isLast
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_lastools_LASPoint_isLast(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->is_last();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    isSingle
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_lastools_LASPoint_isSingle(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->is_single();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    isFirstOfMany
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_lastools_LASPoint_isFirstOfMany(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->is_first_of_many();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    isLastOfMany
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_lastools_LASPoint_isLastOfMany(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->is_last_of_many();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getX
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_org_lastools_LASPoint_getX(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_x();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getY
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_org_lastools_LASPoint_getY(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_y();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getZ
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_org_lastools_LASPoint_getZ(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_z();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getIntensity
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_lastools_LASPoint_getIntensity(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_intensity();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getReturnNumber
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_org_lastools_LASPoint_getReturnNumber(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_return_number();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getNumberOfReturns
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_org_lastools_LASPoint_getNumberOfReturns(
        JNIEnv *env, jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_number_of_returns();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getScanDirectionFlag
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_org_lastools_LASPoint_getScanDirectionFlag(
        JNIEnv *env, jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_scan_direction_flag();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getEdgeOfFlightLine
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_org_lastools_LASPoint_getEdgeOfFlightLine(
        JNIEnv *env, jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_edge_of_flight_line();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getClassification
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_org_lastools_LASPoint_getClassification(
        JNIEnv *env, jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_classification();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getSyntheticFlag
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_org_lastools_LASPoint_getSyntheticFlag(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_synthetic_flag();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getKeypointFlag
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_org_lastools_LASPoint_getKeypointFlag(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_keypoint_flag();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getWithheldFlag
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_org_lastools_LASPoint_getWithheldFlag(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_withheld_flag();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getScanAngleRank
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_org_lastools_LASPoint_getScanAngleRank(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_scan_angle_rank();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getUserData
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_org_lastools_LASPoint_getUserData(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_user_data();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getPointSourceId
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_lastools_LASPoint_getPointSourceId(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_point_source_ID();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getDeletedFlag
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_lastools_LASPoint_getDeletedFlag(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_deleted_flag();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getGPSTime
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_org_lastools_LASPoint_getGPSTime(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_gps_time();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getR
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_lastools_LASPoint_getR(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_R();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getG
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_lastools_LASPoint_getG(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_G();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getB
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_lastools_LASPoint_getB(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_B();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getI
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_lastools_LASPoint_getI(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_I();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    getNIR
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_lastools_LASPoint_getNIR(JNIEnv *env,
        jobject lasPoint) {
    PREAMBLE;
    LASpoint* point = LOAD_LASPOINT_POINTER(lasPoint);
    return point->get_NIR();
    TRAILER(0);
}

/*
 * Class:     org_lastools_LASPoint
 * Method:    dealloc
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_lastools_LASPoint_dealloc
(JNIEnv *env, jobject, jlong ptr) {
    PREAMBLE;
    LASpoint* point = static_cast<LASpoint*>(TO_POINTER(ptr));
    if (point) {
        delete point;
    }
    TRAILER_VOID;
}
