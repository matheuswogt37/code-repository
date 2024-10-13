#include <math.h>     // mathematical functions
#include <pthread.h>  // threads
#include <stdio.h>    // standart input output
#include <stdlib.h>   // compatibility for EXIT's
#include <string.h>   // work with string | strcmp
#include <unistd.h>   // sleep

// GLOBAL VARS
pthread_mutex_t waitQueueSpace;
pthread_mutex_t waitQueueFood;
pthread_mutex_t *resSpace;
pthread_mutex_t *resFood;
int *mutex;
int pi, t, nc, nr;
float r;

// STRUCT
typedef struct {
    int id;
    int population;
} DataThr;

// PARAMS FUNCTIONS START
// _help options show all options to use this program
void _help() {
    printf(
        " \
    Usage: growth_simulation [OPTION]...\n\
    Use to simulate bacterium colonium growth\n\
    \n\
    \tObrigatory params:\n\
    -pi\t\tSet initial population\n\
    -r\t\tSet growth rate\n\
    -t\t\tSet simulation time\n\
    -nc\t\tSet colonies quantity\n\
    -nr\t\tSet resources quantity\n\
    -h,\t--help\tPrint help message\n\
    \n\
    \tOptional params:\t\
    -f [FILE]\t\tWrite the output in a [FILE]\n");
}

// check if obrigratory params are passed and assigned, if ok then procced, if not then return error and exit
int checkParams(int argc, char **argv, int *pi, float *r, int *t, int *nc, int *nr, int *file) {
    int val[5];  // "boolean" if corresponding param were passed
    int i;
    for (i = 0; i < 5; i++) {
        val[i] = 0;  // default value is "false" (0 because use int)
    }

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-pi") == 0) {  // check if is this param
            i++;                            // sum because need to get the param value
            if (i < argc) {                 // if the param value exist
                sscanf(argv[i], "%d", pi);  // assign value
            }
        } else if (strcmp(argv[i], "-r") == 0) {
            i++;
            if (i < argc) {
                sscanf(argv[i], "%f", r);
            }
        } else if (strcmp(argv[i], "-t") == 0) {
            i++;
            if (i < argc) {
                sscanf(argv[i], "%d", t);
            }
        } else if (strcmp(argv[i], "-nc") == 0) {
            i++;
            if (i < argc) {
                sscanf(argv[i], "%d", nc);
            }
        } else if (strcmp(argv[i], "-nr") == 0) {
            i++;
            if (i < argc) {
                sscanf(argv[i], "%d", nr);
            }
        } else if (strcmp(argv[i], "-f") == 0) {
            i++;
            *file = i;  // index of file name
        } else if (strcmp(argv[i], "-h") == 0) {
            _help();
        } else {
            printf("\nParam '%s' not recognized! Try './growth_simulation - help' to check options\nAborting program...\n\n", argv[i]);
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

// PARAMS FUNCTIONS END
void *growth(void *d) {
    DataThr *data = (DataThr *)d;  // get the data struct from void param, this is a litte confusing so i explain this line on report
    int cond = 1;                  // if the lock occured normaly, if not enter the queueMutex
    int indexSpace, indexFood;

    if (0 == (data->id % 2)) {
        // get resource space
        while (1 == cond) {  // while not get space continue trying
            for (int i = 0; i < nr; i++) {
                if (0 == pthread_mutex_trylock(&resSpace[i])) {   // try lock into this mutex, if ok then enter the if, if not then continue until check all the mutexes
                    sleep(rand() % 5 + 2);                                                                         // sleep random betweeen 2 and 7
                    printf("id %d get %d space\n", data->id, i);  // print to know what is going on
                    indexSpace = i;
                    cond = 0;
                    break;
                }
            }
            if (1 == cond) {                                       // enter mutex queueSpace
                printf("id %d enter in queue space\n", data->id);  // print to know what is going on
                pthread_mutex_lock(&waitQueueSpace);
            }
        }
        // get resource food
        cond = 1;
        while (1 == cond) {
            for (int i = 0; i < nr; i++) {
                if (0 == pthread_mutex_trylock(&resFood[i])) {
                        sleep(rand() % 5 + 2);                                                                         // sleep random betweeen 2 and 7
                    printf("id %d get %d food\n", data->id, i);  // print to know what is going on
                    indexFood = i;
                    cond = 0;
                    break;
                }
            }
            if (1 == cond) {
                printf("id %d enter in queue food\n", data->id);  // print to know what is going on
                pthread_mutex_lock(&waitQueueFood);
            }
        }
    } else {
        // get resource food
        while (1 == cond) {
            for (int i = 0; i < nr; i++) {
                if (0 == pthread_mutex_trylock(&resFood[i])) {
                        sleep(rand() % 5 + 2);                                                                         // sleep random betweeen 2 and 7
                    printf("id %d get %d food\n", data->id, i);  // print to know what is going on
                    indexFood = i;
                    cond = 0;
                    break;
                }
            }
            if (1 == cond) {
                printf("id %d enter in queue food\n", data->id);  // print to know what is going on
                pthread_mutex_lock(&waitQueueFood);
            }
        }
        // get resource space
        cond = 1;
        while (1 == cond) {  // while not get space continue trying
            for (int i = 0; i < nr; i++) {
                if (0 == pthread_mutex_trylock(&resSpace[i])) {   // try lock into this mutex, if ok then enter the if, if not then continue until check all the mutexes
                    sleep(rand() % 5 + 2);                                                                         // sleep random betweeen 2 and 7
                    printf("id %d get %d space\n", data->id, i);  // print to know what is going on
                    indexSpace = i;
                    cond = 0;
                    break;
                }
            }
            if (1 == cond) {                                       // enter mutex queueSpace
                printf("id %d enter in queue space\n", data->id);  // print to know what is going on
                pthread_mutex_lock(&waitQueueSpace);
            }
        }
    }

    // now make the equation
    data->population *= exp((r * t));                                                              // calculate the new population
    sleep(rand() % 5 + 2);                                                                         // sleep random betweeen 2 and 7
    printf("id %d init population %d \t\tfinal population %d\n", data->id, pi, data->population);  // print to know what is going on
    // unlock resources
    pthread_mutex_unlock(&resSpace[indexSpace]);
    pthread_mutex_unlock(&resFood[indexFood]);

    // unlock queueResources
    pthread_mutex_unlock(&waitQueueSpace);
    pthread_mutex_unlock(&waitQueueFood);

    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    int status, ifFile;
    DataThr **threadsData, *aux, *auxTwo;
    pthread_t *threads;
    pthread_attr_t attr;

    // random sleep
    time(NULL);

    // params validation
    if (EXIT_FAILURE == checkParams(argc, argv, &pi, &r, &t, &nc, &nr, &ifFile)) {  // if check result in error
        perror("Error on checkParams!");
        exit(EXIT_FAILURE);
    }
    // memory allocation
    resSpace = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nr);
    resFood = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nr);
    threadsData = (DataThr **)malloc(sizeof(DataThr *) * nc);
    // alloc memory and define the values
    for (int i = 0; i < nc; i++) {
        threadsData[i] = (DataThr *)malloc(sizeof(DataThr));
        threadsData[i]->id = i;
        threadsData[i]->population = pi;
    }
    // alloc threads array memory
    threads = (pthread_t *)malloc(sizeof(pthread_t) * nc);

    // init resources mutex's
    for (int i = 0; i < nr; i++) {
        pthread_mutex_init(&resSpace[i], NULL);
    }
    for (int i = 0; i < nr; i++) {
        pthread_mutex_init(&resFood[i], NULL);
    }

    // init resources queueMutex
    pthread_mutex_init(&waitQueueSpace, NULL);
    pthread_mutex_init(&waitQueueFood, NULL);

    // thread attribute
    pthread_attr_init(&attr);                                     // init attr
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);  // when finish execution need the mother process listen this (usign pthread_join()) to deallocate thread resources. Opossite of deatach thread

    // init threads (colonies)
    for (int i = 0; i < nc; i++) {
        threadsData[i]->id = i;

        status = pthread_create(&threads[i], &attr, growth, threadsData[i]);  // create thread and assign the function, the threadData is the struct that is used as input and output
        if (status) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    // wait all threads finish their functions
    for (int i = 0; i < nc; i++) {
        status = pthread_join(threads[i], NULL);
        if (status) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }
    // free's
    free(threads);
    for (int i = 0; i < nc; i++) {
        free(threadsData[i]);
    }
    free(threadsData);
    free(resFood);
    free(resSpace);
    printf("End...\n");  // only to know if reach end
    return EXIT_SUCCESS;
}