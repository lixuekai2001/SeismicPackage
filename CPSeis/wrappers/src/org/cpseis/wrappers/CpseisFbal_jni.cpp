//////// DO NOT EDIT THIS FILE - it is machine generated ////////

#include "CpseisFbal.hh"
#include <jni.h>

extern "C"
{
  JNIEXPORT jlong JNICALL Java_org_cpseis_wrappers_CpseisFbal_nativeCreate
    (JNIEnv *env, jobject obj)
  {
    CpseisFbal *module = new CpseisFbal();
    return (jlong)module;
  }
}