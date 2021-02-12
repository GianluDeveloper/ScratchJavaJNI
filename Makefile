
JAVA_HOME=$(shell readlink -f /usr/bin/javac | sed "s:bin/javac::")
BUILD_DIR:=build
$(shell mkdir -p ${BUILD_DIR})

all: JavaHeader ScratchJNI ScratchJNIJava JavaHeaderFromC JavaFromC JavaFromCJava

JavaHeader: ScratchJNI.java
	javac -d ${BUILD_DIR} -h ${BUILD_DIR} ScratchJNI.java

ScratchJNI: ScratchJNI.c
	gcc -fPIC -I"$(JAVA_HOME)/include" -I"${BUILD_DIR}" -I"$(JAVA_HOME)/include/linux" -shared -o ${BUILD_DIR}/libscratchjni.so ScratchJNI.c 

ScratchJNIJava: ScratchJNI.java
	javac -d ${BUILD_DIR} ScratchJNI.java

JavaHeaderFromC: JavaFromC.java
	javac -d ${BUILD_DIR} -h ${BUILD_DIR} JavaFromC.java

JavaFromC: JavaFromC.c
	gcc -fPIC -I"$(JAVA_HOME)/include" -I"${BUILD_DIR}" -I"$(JAVA_HOME)/include/linux" -shared -o ${BUILD_DIR}/libjavafromc.so JavaFromC.c 

JavaFromCJava: JavaFromC.java
	javac -d ${BUILD_DIR} JavaFromC.java

run: 
	java -classpath ./build -Djava.library.path=./build  ScratchJNI
runJavaFromC: 
	java -classpath ./build -Djava.library.path=./build  JavaFromC

clean:
	rm -rf ${BUILD_DIR}