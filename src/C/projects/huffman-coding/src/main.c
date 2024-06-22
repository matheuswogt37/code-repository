// libs
#include <stdio.h>

// my libs
#include "utils/freqTable.c"
#include "utils/doublyLinkedList.c"

// global vars/const

// prototyping

char *getReadName(char **argv);
char *getWriteName(char **argv);
void completeFreqTable(List *list, FreqNode **freqTable);

// main function
int main(int argc, char **argv) {
    // var to read pure file
    FILE *read_f;
    // var to write encoded file
    FILE *write_f;
    // list that will contain all characters from read_f
    List *chars;
    // frequency table, pointer to root/first element
    FreqNode *rootFreq;
    rootFreq = NULL;

    // other vars
    char *readName;
    char ch;

    //todo descomentar a seguinte linha e remover a seguinte-seguinte       MOTIVO - fiz apenas para debugar
    //readName = getReadName(argv);
    readName = "files/text";
    
    read_f = fopen(readName, "r");

    // if file couldnot be opened then abort main, return EXIT_FAILURE (stdio.h const) that is equal 1
    if (NULL == read_f) {
        printf("ERROR\tfile couldnot opened!\naborting...");
        return EXIT_FAILURE;
    }

    // alloc list
    chars = allocList();

    // loop to insert all characters into a list
    for (ch = fgetc(read_f); EOF != ch; ch = fgetc(read_f)) {
        insertNode(chars, chars->tail, ch);
    }

    //todo debug print
    printList(chars);
    printf("\n");

    // pass all chars to frequency table
    completeFreqTable(chars, &rootFreq);

    // balance frequency table
    balanceFreqTable(&rootFreq);

    //todo debug print
    printFreqTable(&rootFreq);

    

    // final instructions
    printf("finalizou\n");

    freeList(chars);
    return EXIT_SUCCESS;
}

// functions

// passing main parameters and return name of read file, the first parameter
char *getReadName(char **argv) {
    return argv[1];
}

// passing main parameters and return name of write file, the second parameter
char *getWriteName(char **argv) {
    return argv[2];
}

// complete frequency table using all characters provides by read_file
void completeFreqTable(List *rootList, FreqNode **rootFreq) {
    Node *auxOne, *auxTwo;
    char ch;
    int count;

    auxOne = rootList->head;
    if (NULL != auxOne) {
        ch = auxOne->info;
    }
    count = 0;
    while (NULL != auxOne) {
        // loop entire list counting frequencies and removing the letters allredy counted
        while (NULL != auxOne) {
            if (auxOne->info == ch) { 
                count++;
                auxTwo = auxOne->next;
                removeNode(rootList, auxOne);
                auxOne = auxTwo;
            } else {
                auxOne = auxOne->next;
            }
        }

        // insert the letter in frequency table
        insertFreqNode(rootFreq, ch, count);



        // "reboot" vars
        auxOne = rootList->head;
        if (NULL != auxOne) {
            ch = auxOne->info;
        }
        count = 0;
    }
}