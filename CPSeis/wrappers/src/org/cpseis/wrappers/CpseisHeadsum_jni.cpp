//////// DO NOT EDIT THIS FILE - it is machine generated ////////

#include "CpseisHeadsum.hh"
#include <jni.h>

extern "C"
{
  JNIEXPORT jlong JNICALL Java_org_cpseis_wrappers_CpseisHeadsum_nativeCreate
    (JNIEnv *env, jobject obj)
  {
    CpseisHeadsum *module = new CpseisHeadsum();
    return (jlong)module;
  }
}