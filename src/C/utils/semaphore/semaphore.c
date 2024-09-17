#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define NUM_THREADS 10
#define NUM_STEPS 100

int count = 0;
sem_t semaphore;

void *threadBody(void *id) {
    for (int i = 0; i < NUM_STEPS; i++) {
        sem_wait(&semaphore);
        count++;
        sem_post(&semaphore);
    }
    pthread_exit(NULL);
}

int main() {
    // pthread_t threads[NUM_THREADS];
    // pthread_attr_t attr;

    // sem_init(&semaphore);

    // pthread_attr_init(&attr);
    // pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    printf("hello log\n");

    pthread_exit(0);
}