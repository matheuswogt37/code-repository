#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define NUM_WILD 5
#define CALDRON_SIZE 5

sem_t caldron;  // caldron ractions
int remain_food = CALDRON_SIZE;

void sleepRandom() {
    int randSleep = rand() % 2 + 3;
    sleep(randSleep);
}

void wakeChef() {
    remain_food = CALDRON_SIZE;
}

void *wildBody(void *id) {
    int i = (long int)id;
    while (1) {
        sem_wait(&caldron);
        if (remain_food == 0) {
            printf("Selvagem %d acordou o cozinheiro\n", i);
            wakeChef();
        }
        remain_food--;
        printf("Selvagem %d comeu - comida restante %ls\n", i, &remain_food);
        sem_post(&caldron);
        sleepRandom();
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t wilds[NUM_WILD];
    pthread_attr_t attr;
    long status;
    srand(time(NULL));  

    sem_init(&caldron, 0, 1);

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    setvbuf(stdout, 0, _IONBF, 0);

    for (long i = 0; i < NUM_WILD; i += 1) {
        status = pthread_create(&wilds[i], &attr, wildBody, (void *)i);
        // if (status) {
        //     perror("pthread_create");
        //     exit(1);
        // }
    }

    pthread_exit(NULL);
    return 0;
}