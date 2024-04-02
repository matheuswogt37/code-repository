#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 5
#define Y 10

char randChar()
{
    int mod = rand() % 2;
    switch (mod)
    {
    case 1:
        return 'A';
        break;
    case 0:
        return 'B';
        break;

    default:
        break;
    }
}

void showArray(char array[X][Y])
{
    for (int i = 0; i < Y; i++)
    {
        printf("%s", array[i]);
        // for (int j = 0; j < X; j++)
        // {
        //     printf("%c ", array[j][i]);
        // }
        printf("\n");
    }
}

void setArray(char array[X][Y])
{
    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
        {
            array[j][i] = randChar();
        }
    }
}

int main()
{

    srand(time(NULL));
    char array[X][Y];
    setArray(array);
    showArray(array);

    return 1;
}