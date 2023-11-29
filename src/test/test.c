#include <stdio.h>
#include <stdlib.h>


static void staticHelloWorld () {
    printf("Hello world!\n");
}

void helloWord() {
    staticHelloWorld();
}

#undef staticHelloWord