# Java JNI Starter Template

A Demo [Java JNI](https://en.wikipedia.org/wiki/Java_Native_Interface) API example to use as a starting point for Java Native Interface projects.

For those who don't know it, JNI is a bridge between JVM and native machine code instructions (this ScratchJNI uses a C binary).

To compile and run under Linux (you need gcc & JDK installed correctly), use the simple Makefile provided doing:

```
make
make run
```

The output'll be something like that:

```

Hello World (https://gianlu.dev/) 14!
The response from C is: I'm the C boss!

```

To run Java method from C:

```
make
make runJavaFromC
```

Output:

```

ok from c (2)
ok of java
in the main

```
