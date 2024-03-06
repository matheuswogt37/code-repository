#include<stdio.h>

int receiveNumber() {
    int n;
    printf("Digite o seu numero: ");
    scanf("%i", &n);
    return n;
}


int main() {


    int lower, higher, num, qtdNums;
    qtdNums = 20;

    printf("\n\n\n\n\n##############################################\n");
    printf("Este programa recebe 20 numeros\n");
    printf("Retornando o maior e o menor\n");

    num = receiveNumber();
    lower = higher = num;
    for (int i = 0; i < (qtdNums - 1); i++) {
        num = receiveNumber();
        if (num > higher) {
            higher = num;
        }
        if (num < lower) {
            lower = num;
        }
    }

    printf("\n");
    printf("Numero mais alto: %i\n", higher);
    printf("Numero mais baixo: %i\n", lower);

    return 0;
}