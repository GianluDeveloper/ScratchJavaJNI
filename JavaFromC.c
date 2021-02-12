// gcc -fPIC -I/usr/lib/jvm/java-15-openjdk-amd64/include -I./build/ -I"/usr/lib/jvm/java-15-openjdk-amd64/include/linux" -shared -o build/libasync.so Async.c
// javac -d build Async.java
// java -classpath ./build -Djava.library.path=./build  Async
#include "JavaFromC.h"
JNIEXPORT jstring JNICALL Java_JavaFromC_intheC(JNIEnv *env, jobject foo_obj, jint n)
{
    printf("ok da c (%d)\n", n);
    const char *msg = "hiii im c";
    jstring result = (*env)->NewStringUTF(env, msg);

    jclass cls_foo = (*env)->GetObjectClass(env, foo_obj);

    // get the method IDs from that class
    // jmethodID mid_callback = (*env)->GetMethodID(env, cls_foo, "callback", "()V");
    jmethodID mid_callback_static = (*env)->GetStaticMethodID(env, cls_foo, "testit", "()V");

    // then call them.
    // (*env)->CallVoidMethod(env, foo_obj, mid_callback);
    (*env)->CallStaticVoidMethod(env, cls_foo, mid_callback_static);
    return result;
}
