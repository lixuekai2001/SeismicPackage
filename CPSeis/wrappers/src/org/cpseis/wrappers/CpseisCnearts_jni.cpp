//////// DO NOT EDIT THIS FILE - it is machine generated ////////

#include "CpseisCnearts.hh"
#include <jni.h>

extern "C"
{
  JNIEXPORT jlong JNICALL Java_org_cpseis_wrappers_CpseisCnearts_nativeCreate
    (JNIEnv *env, jobject obj)
  {
    CpseisCnearts *module = new CpseisCnearts();
    return (jlong)module;
  }
}