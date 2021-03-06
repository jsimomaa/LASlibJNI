/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_lastools_LASPoint */

#ifndef _Included_org_lastools_LASPoint
#define _Included_org_lastools_LASPoint
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_lastools_LASPoint
 * Method:    isFirst
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_lastools_LASPoint_isFirst
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    isIntermediate
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_lastools_LASPoint_isIntermediate
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    isLast
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_lastools_LASPoint_isLast
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    isSingle
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_lastools_LASPoint_isSingle
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    isFirstOfMany
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_lastools_LASPoint_isFirstOfMany
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    isLastOfMany
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_lastools_LASPoint_isLastOfMany
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getX
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_org_lastools_LASPoint_getX
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getY
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_org_lastools_LASPoint_getY
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getZ
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_org_lastools_LASPoint_getZ
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getIntensity
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_lastools_LASPoint_getIntensity
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getReturnNumber
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_org_lastools_LASPoint_getReturnNumber
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getNumberOfReturns
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_org_lastools_LASPoint_getNumberOfReturns
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getScanDirectionFlag
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_org_lastools_LASPoint_getScanDirectionFlag
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getEdgeOfFlightLine
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_org_lastools_LASPoint_getEdgeOfFlightLine
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getClassification
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_org_lastools_LASPoint_getClassification
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getSyntheticFlag
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_org_lastools_LASPoint_getSyntheticFlag
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getKeypointFlag
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_org_lastools_LASPoint_getKeypointFlag
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getWithheldFlag
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_org_lastools_LASPoint_getWithheldFlag
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getScanAngleRank
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_org_lastools_LASPoint_getScanAngleRank
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getUserData
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_org_lastools_LASPoint_getUserData
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getPointSourceId
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_lastools_LASPoint_getPointSourceId
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getDeletedFlag
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_lastools_LASPoint_getDeletedFlag
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getGPSTime
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_org_lastools_LASPoint_getGPSTime
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getR
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_lastools_LASPoint_getR
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getG
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_lastools_LASPoint_getG
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getB
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_lastools_LASPoint_getB
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getI
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_lastools_LASPoint_getI
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    getNIR
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_lastools_LASPoint_getNIR
  (JNIEnv *, jobject);

/*
 * Class:     org_lastools_LASPoint
 * Method:    alloc
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_lastools_LASPoint_alloc
  (JNIEnv *, jclass);

/*
 * Class:     org_lastools_LASPoint
 * Method:    dealloc
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_lastools_LASPoint_dealloc
  (JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
