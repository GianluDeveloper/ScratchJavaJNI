#include <stdio.h>
#include "ScratchJNI.h"

JNIEXPORT jstring JNICALL Java_ScratchJNI_callTheC(JNIEnv *env, jobject javaObject, jint n, jstring s)
{
  const char *str = (*env)->GetStringUTFChars(env, s, 0);
  printf("Hello World (%s) %d!\n", str, n);
  char *msg = "I'm the C boss!";
  // testCurl(str);
  jstring result = (*env)->NewStringUTF(env, msg);
  return result;
}

// #include <curl/curl.h>

// int testCurl(const char *url)
// {
//   printf("Doing %s\n", url);
//   CURL *curl;
//   CURLcode res;

//   curl = curl_easy_init();
//   if (curl)
//   {
//     curl_easy_setopt(curl, CURLOPT_URL, url);
//     /* example.com is redirected, so we tell libcurl to follow redirection */
//     curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

//     /* Perform the request, res will get the return code */
//     res = curl_easy_perform(curl);
//     /* Check for errors */
//     if (res != CURLE_OK)
//       fprintf(stderr, "curl_easy_perform() failed: %s\n",
//               curl_easy_strerror(res));

//     /* always cleanup */
//     curl_easy_cleanup(curl);
//   }
//   return 0;
// }