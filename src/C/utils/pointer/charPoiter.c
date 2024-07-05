#include <stdio.h>
#include <stdlib.h>

int main() {
    char *ch1;
    char *ch2;
    int qtdCh1 = 3;
    int qtdCh2 = 5;
    
    ch1 = (char *) malloc(sizeof(char) * qtdCh1);
    ch2 = (char *) malloc(sizeof(char) * qtdCh2);
    
    //* ch1 populate
    ch1[0] = 'a';
    ch1[1] = 'b';
    ch1[2] = 'c';
    
    //* ch2 populate
    ch2[0] = 'd';
    ch2[1] = 'e';
    ch2[2] = 'f';
    ch2[3] = 'g';
    
    //* prints
    for (int i = 0; i < qtdCh1; i++) {
        printf("%c", ch1[i]);
    }
    printf("\nsizeof(ch1) = %li\n", sizeof(ch1));
    printf("\n");
    for (int i = 0; i < qtdCh2; i++) {
        printf("%c", ch2[i]);
    }
    printf("\nsizeof(ch2) = %li\n", sizeof(ch2));
    printf("\n");

    free(ch1);
    free(ch2);
    return 0;
}