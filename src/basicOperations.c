#include<stdio.h>
#define TAM 10

void pressEnter() {
    printf("Press Enter to Continue\n");
    while( getchar() != '\n');
    printf("\n");
}

int main() {
    float x, x2, sizeFloat;
    int x3, command, sizeInt, cond;
    char sizeChar, sizeArrayChar[TAM] = "tamanho";
    double sizeDouble;
    cond = 1;
    do {
        printf("1 - Basic operations\n2 - Assignment Operators\n3 - Comparison Operators\n4 - Logical Operators\n5 - Sizeof Operator\n6 - exit\n");
        scanf("%i", &command);

        switch(command) {
            case 1:
                printf("<-----Basic Operations----->\n");
                printf("+ : sum\t\t\t5 + 2 = 7\n");
                printf("- : subtraction\t\t5 - 2 = 3\n");
                printf("/ : division\t\t10 / 5 = 2\n");
                printf("* : multiplication\t10 * 2 = 20\n");
                printf("%% : modulus\t\t10 %% 3 = 1\n");
                pressEnter();
                break;
            case 2:
                printf("<h1>Assignment Operators</h1>\n");
                x = x2 = 5;
                printf("x = 5\n");
                x2 += 3;
                printf("x += 3 {%.2f}\n", x2);
                x2 = x;
                x2 -= 2;
                printf("x -= 2 {%.2f}\n", x2);
                x2 = x;
                x2 *= 5;
                printf("x *= 5 {%.2f}\n", x2);
                x2 = x;
                x2 /= 2;
                printf("x /= 2 {%.2f}\n", x2);
                x2 = x;
                x3 = x;
                x3 %= 3;
                printf("x %%= 3 {%i} [only int x]\n", x3);
                x3 = x;
                x3 &= 7; 
                printf("x &= 7 {%i} [only int x]\n", x3);
                x3 = x;
                x3 |= 3;
                printf("x |= 3 {%i} [only int x]\n", x3);
                x3 = x;
                x3 ^= 2;
                printf("x ^= 2 {%i} [only int x]\n", x3);
                x3 = x;
                x3 >>= 2;
                printf("x >>= 2 {%i} [only int x]\n", x3);
                x3 = x;
                x3 <<= 2;
                printf("x <<= 2 {%i} [only int x]\n", x3);
                x3 = x;
                break;
            case 3:
                printf("-----<Comparison Operations>-----\n");
                printf("< : less than\n");
                printf("> : greater than\n");
                printf("<= : less or equal than\n");
                printf(">= : greater or equal than\n");
                printf("== : equal than\n");
                printf("!= : not equal than\n");
                break;
            case 4:
                // && || !
                printf("\n\t&&\n\tAND\nif ((1>2) && (3==2)) result in FALSE\nif ((2<=5) && (9>0)) result in TRUE\n");
                printf("\n\t||\n\tOR\nif ((2>=3) || (0>9)) result in FALSE\nif ((1>2) || (3==2)) result in TRUE\n");
                printf("\n\t!\n\tNOT\nif (3!=3) result in FALSE\nif (3!=4) result in TRUE");
                break;
            case 5:
                printf("return memory size (bytes) of a data type or variable\n");
                // int float double char char[]
                sizeInt = 45;
                printf("sizeInt = %i | sizeof(%llu)\n", sizeInt, sizeof(sizeInt));
                sizeFloat = 37.89;
                printf("sizeFloat = %2.f | sizeof(%llu)\n", sizeFloat, sizeof(sizeFloat));
                sizeDouble = 23.11;
                printf("sizeDouble = %2.f | sizeof(%llu)\n", sizeDouble, sizeof(sizeDouble));
                sizeChar = 'F';
                printf("sizeChar = %c | sizeof(%llu)\n", sizeChar, sizeof(sizeChar));
                //sizeArrayChar[TAM] = "tamanho"
                printf("sizeArrayChar[%i] = %s | sizeof(%llu)\n", TAM, sizeArrayChar, sizeof(sizeArrayChar));
                break;
            case 6:
                cond = 0;
                break;
            default:
                printf("Comando invalido!\n");
                break;
        }
    } while (cond == 1);
    

    


    



    return 0;
}