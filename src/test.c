#include<stdio.h>
#define TAM 10

int main() {
    char array[TAM] = "tamanho";
    int x;
    scanf("%i", &x);

    printf("Press enter to continue\n");
    char enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); }
    printf("Thank you for pressing enter\n");

    printf("passou");

    return 0;
}