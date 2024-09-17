#include <pthread.h>
#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <string>

#include "ThreadData/ThreadData.hpp"
#include "ThreadFunctions/ThreadFunctions.hpp"

#define THREAD_QTD 100
#define QTD_LINES_PER_THREAD 1000

std::string getBatch(std::ifstream *file) {
    std::string str;
    std::string temp;
    for (int i = 0; i < QTD_LINES_PER_THREAD; i++) {
        std::getline(*file, temp);
        str += temp + " ";
        if (file->eof()) {
            break;
        }
    }
    return str;
}

int main() {
    pthread_t threads[THREAD_QTD];
    std::ifstream file("logs/access2.log");
    std::string batch;
    int result, sumStatus200, i;
    int sumHour[24] = {0};
    int tempHour[24];
    ThreadData *thrNum[THREAD_QTD];

    for (i = 0; i < THREAD_QTD; i++) {
        thrNum[i] = (ThreadData *)malloc(sizeof(ThreadData));
        thrNum[i] = new ThreadData(i);
        if (NULL == thrNum[i]) {
            fprintf(stderr, "Memory allocation error!\n");
            exit(EXIT_FAILURE);
        }
    }

    // for (i = 0; i < THREAD_QTD; i++) {
    //     thrNum[i] = new ThreadData(i);

    //     batch = getBatch(&file);
    //     if ("" != batch) {
    //         thrNum[i]->setStr(batch);

    //         result = pthread_create(&threads[i], NULL, foo, thrNum[i]);
    //         if (0 != result) {
    //             fprintf(stderr, "Create thread error!\n");
    //             exit(EXIT_FAILURE);
    //         }
    //     } else {
    //         break;
    //     }
    // }
    // for (i = 0; i < THREAD_QTD; i++) {
    //     pthread_join(threads[i], NULL);  //* wait final finish
    // }
    do {
        for (i = 0; i < THREAD_QTD; i++) {
            batch = getBatch(&file);
            if (" " != batch) {
                thrNum[i]->setStr(batch);

                result = pthread_create(&threads[i], NULL, foo, thrNum[i]);
                if (0 != result) {
                    fprintf(stderr, "Create thread error!\n");
                    exit(EXIT_FAILURE);
                }
            } else {
                break;
            }
        }
        for (int j = 0; j < i; j++) {
            pthread_join(threads[j], NULL);  //* wait final finish
        }
    } while (" " != batch);

    sumStatus200 = 0;
    for (i = 0; i < THREAD_QTD; i++) {
        sumStatus200 += thrNum[i]->getStatus200();
        thrNum[i]->getSumHour(tempHour);
        for (int j = 0; j < 24; j++) {
            sumHour[j] += tempHour[j];
        }
    }

    std::cout << "Status 200 totais -> " << sumStatus200 << std::endl;
    for (i = 0; i < 24; i++) {
        std::cout << "Hora " << i << " -> " << sumHour[i] << std::endl;
    }

    printf("Finalizando...\n");
    return 0;
}