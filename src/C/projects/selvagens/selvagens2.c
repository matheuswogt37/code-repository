#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define QTD_WILDS 5
#define CAULDRON_SIZE 5

pthread_t chef;
pthread_mutex_t cauldron;
sem_t food;

void *wildFunct(void *id) {
    int* thrNum = (int*) id;
    int sleepTime = rand() % 10+1;

    printf("THREAD %d dormira por %d seg\n", *thrNum, sleepTime);

    sleep(sleepTime);

    printf("THREAD %d acordou\n", *thrNum);
    free(thrNum);
    pthread_exit(NULL);
}

void *chefFunct(void *id) {
    int* thrNum = (int*) id;
    
}

int main() {
    pthread_t wilds[QTD_WILDS];
    int res;

    for (int i = 0; i < QTD_WILDS; i++) {
        int *thrNum = malloc(sizeof(int));
        if (NULL == thrNum) {
            fprintf(stderr, "Erro de alocação de memória\n");
            exit(EXIT_FAILURE);
        }
        *thrNum = i+1;

        res = pthread_create(&wilds[i], NULL, wildFunct, thrNum);
        if (0 != res) {
            fprintf(stderr, "Erro ao criar a thread %d\n", i + 1);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < QTD_WILDS; i++) {
        pthread_join(wilds[i], NULL);
    }

    printf("hello world");

    return 0;
}