#include <stdio.h>
#include <stdlib.h>

int *mallocInt(int size);
char *mallocStr(int size);
void input(char *asciiStr);
void convert(char *asciiStr, int *asciiCode);
void output(char *asciiStr, int *asciiCode);
void freeStr(char *str);
void freeInt(int *i);


int *mallocInt(int size) {
    int *i;
    i = (int *) malloc(sizeof(int) * size);
    return i;
}

char *mallocStr(int size)
{
    char *str;
    str = (char *) malloc(sizeof(char) * size);
    return str;
}

void input(char *asciiStr)
{
    printf("Digite a frase a ser convertida\n");
    scanf("%s", asciiStr);
}

void convert(char *asciiStr, int *asciiCode) {
    
}

void freeStr(char *str) {
    
}
void freeInt(int *i);