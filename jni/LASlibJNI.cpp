/*
 * LASlibJNI.c
 *
 *  Created on: Dec 1, 2016
 *      Author: jani
 */


#include <jni.h>
#include <stdio.h>
#include <string>
#include <exception>
#include <stdexcept>

#include "org_lastools_LASlibJNI.h"
#include "globals.cpp"
#include "class_LASHeader.cpp"
#include "class_LASPoint.cpp"
#include "class_LASReader.cpp"

/*
 * Class:     org_lastools_LASlibJNI
 * Method:    nativeInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_lastools_LASlibJNI_nativeInit
  (JNIEnv *env, jclass c) {
    PREAMBLE;
    if (initialized) return;
    if (init_ids(env))
        initialized=true;
    TRAILER_VOID;
}
