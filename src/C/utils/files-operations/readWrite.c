#include <stdio.h>
#define READ_F "files/shortFile"
#define WRITE_F "music"

long int findSize(FILE *f)
{
    long int size;

    fseek(f, 0L, SEEK_END);
    size = ftell(f);
    fseek(f, 0L, SEEK_SET);

    return size;
}

int main()
{
    FILE *read_ptr;
    long int size;
    int charac;
    int cont = 0;
    read_ptr = fopen(READ_F, "r");

    size = findSize(read_ptr);
    printf("size - %li\n", size);

    printf("Content of %s\n", READ_F);
    
    while (cont < size)
    {
        printf("%c", fgetc(read_ptr));
        cont++;
    }
    printf("\ncont - %i\n", cont);

    return 0;
}