typedef enum { FALSE,
               TRUE } boolean;

//* bits moves
int move_bit(int num, int qtd_move, boolean left) {
    int aux = num;
    if (TRUE == left) {
        num <<= qtd_move;
        printf("\nMove left\n");
        printf("%d << %d\t%d\n", aux, qtd_move, num);
    } else {
        num >>= qtd_move;
        printf("\nMove right\n");
        printf("%d >> %d\t%d\n", aux, qtd_move, num);
    }
    return num;
}

//* not bit
int not_bit(int num) {
    int aux = num;
    num = ~num;
    printf("\nNot\n");
    printf("~%d = %d\n", aux, num);
    return num;
}

//* and bit
int and_bit(int n1, int n2) {
    int res;
    res = n1 & n2;
    printf("\nAnd\n");
    printf("%d & %d = %d\n", n1, n2, res);
    return res;
}

//* or bit
int or_bit(int n1, int n2) {
    int res;
    res = n1 | n2;
    printf("\nOr\n");
    printf("%d | %d = %d\n", n1, n2, res);
    return res;
}

//* xor bit
int xor_bit(int n1, int n2) {
    int res;
    res = n1 ^ n2;
    printf("\nXor\n");
    printf("%d ^ %d = %d\n", n1, n2, res);
    return res;
}