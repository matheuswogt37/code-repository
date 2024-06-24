#include <stdio.h>
#include <stdlib.h>

int main() {
    char ch = 'A'; // Exemplo de char
    int bit_position = 3; // Posição do bit a definir (0-indexed)
    
    ch |= (1 << bit_position);
    
    printf("%c", ch);

    return 0;
}