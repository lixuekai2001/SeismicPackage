//////// DO NOT EDIT THIS FILE - it is machine generated ////////

#include "CpseisSdip.hh"
#include <jni.h>

extern "C"
{
  JNIEXPORT jlong JNICALL Java_org_cpseis_wrappers_CpseisSdip_nativeCreate
    (JNIEnv *env, jobject obj)
  {
    CpseisSdip *module = new CpseisSdip();
    return (jlong)module;
  }
}
