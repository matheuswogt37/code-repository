#include <stdio.h>
#include <stdlib.h>

void input(char asciiStr[]);
void convert(char asciiStr[], int asciiCode[]);
void outputShow(char asciiStr[], int asciiCode[]);

void input(char asciiStr[])
{
    int size = (sizeof(asciiStr) / sizeof(char));
    printf("Escreva a frase a ser convertida (max - %i)\n", size);
    //fgetc(asciiStr, size, stdin);
    printf("%s", asciiStr);
}