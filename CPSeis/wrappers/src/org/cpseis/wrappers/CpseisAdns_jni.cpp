//////// DO NOT EDIT THIS FILE - it is machine generated ////////

#include "CpseisAdns.hh"
#include <jni.h>

extern "C"
{
  JNIEXPORT jlong JNICALL Java_org_cpseis_wrappers_CpseisAdns_nativeCreate
    (JNIEnv *env, jobject obj)
  {
    CpseisAdns *module = new CpseisAdns();
    return (jlong)module;
  }
}
