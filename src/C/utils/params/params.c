#include <stdio.h>

int main(int argc, char **argv) {

    printf("your param size - %i \n", argc);
    for (int i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }

    return 0;
}