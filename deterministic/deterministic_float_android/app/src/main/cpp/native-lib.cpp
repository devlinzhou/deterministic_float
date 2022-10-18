#include <jni.h>
#include <string>
#include <iostream>
#include "../../../../../deterministic_float.h"
#include <android/log.h>

#define  LOG_TAG    "foo"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_testcpp_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */)
{
    std::string hello = "Helloasdfasfs from C++";

    TestGFloat TG;
    TG.Run();

    return env->NewStringUTF(hello.c_str());
}
