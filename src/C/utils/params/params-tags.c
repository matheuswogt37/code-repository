#include <stdio.h>
#include <string.h>

void _help() {
    printf(
        " \
    Usage: params-tags.c.out [OPTIONS]\n \
    -h, --help\t\t print help message\n \
    -w, --world\t\t print world message\n \
    -g, --godbye\t\t print bye message\n ");
}

void _hello() {
    printf("hello world!\n");
}

void _goodbye() {
    printf("goodbye world!\n");
}

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        if ((strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)) {
            _help();
        } else if ((strcmp(argv[i], "-w") == 0 || strcmp(argv[i], "--world") == 0)) {
            _hello();
        } else if ((strcmp(argv[i], "-g") == 0 || strcmp(argv[i], "--goodbye") == 0)) {
            _goodbye();
        } else {
            printf("\tCommand %s not recornized!\n\ttry with '-h' or '--help' for more information\n", argv[i]);
            break;
        }
    }

    return 0;
}