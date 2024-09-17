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

int main() {
    pthread_t wilds[QTD_WILDS];

    printf("hello world");

    return 0;
}