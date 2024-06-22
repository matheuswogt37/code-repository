#include <stdio.h>
#include <stdlib.h>

typedef struct sFreqNode {
    char let;
    int freq;
    struct sFreqNode *next;
    struct sFreqNode *prev;
} FreqNode;

FreqNode *createFreqNode(char ch, int count) {
    FreqNode *node;
    node = (FreqNode *)malloc(sizeof(FreqNode));
    if (NULL != node) {
        node->let = ch;
        node->freq = count;
        node->next = NULL;
        node->prev = NULL;
    }

    return node;
}

void freeFreqTable(FreqNode *root) {
    FreqNode *aux;
    while (NULL != root) {
        aux = root->next;
        free(root);
        root = aux;
    }
}

void newNode(FreqNode **root, char ch, int count) {
    FreqNode *aux, *node;
    aux = (*root);
    node = createFreqNode(ch, count);
    if (NULL == aux) {
        (*root) = node;
    } else {
        while (NULL != aux->next) {
            aux = aux->next;
        }
        aux->next = node;
        node->prev = aux;
    }
}

void insertFreqNode(FreqNode **root, char ch) {
    FreqNode *aux;
    aux = (*root);
    while (NULL != aux) {
        if (aux->let == ch) {
            aux->freq++;
            break;
        }
        aux = aux->next;
    }
    if (NULL == aux) {
        newNode(root, ch, 1);
    }
    
}

// balance frequency table using bubble sort, is not the most effective but works
// future update can transfer the concept of balance table to insert, puting the letter on the final position
void balanceFreqTable(FreqNode **root) {
    FreqNode *auxOne, *auxTwo;
    int cond;

    do {
        cond = 1;
        auxOne = (*root);
        while (NULL != auxOne->next) {
            auxTwo = auxOne->next;
            if (auxOne->freq > auxTwo->freq) {
                cond = 0;

                // change the 'sides'
                if (NULL != auxOne->prev) {
                    auxOne->prev->next = auxTwo;
                }
                if (NULL != auxTwo->next) {
                    auxTwo->next->prev = auxOne;
                }
                // change the semi-middles
                auxOne->next = auxTwo->next;
                auxTwo->prev = auxOne->prev;
                // change the middles
                auxOne->prev = auxTwo;
                auxTwo->next = auxOne;
                // change the root
                if (auxOne == (*root)) {
                    (*root) = auxTwo;
                }
                auxOne = auxOne;
            } else {
                auxOne = auxOne->next;
            }
        }
    } while (0 == cond);
}

void printFreqTable(FreqNode **root) {
    FreqNode *aux;
    aux = (*root);
    printf("#---#------\n");
    while (NULL != aux) {
        if ('\n' == aux->let) {
            printf("| \\n | %i\n", aux->freq);
        } else {
            printf("| %c | %i\n", aux->let, aux->freq);

        }
        aux = aux->next;
    }
}