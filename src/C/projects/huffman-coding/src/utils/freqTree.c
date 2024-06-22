#include <stdio.h>
#include <stdlib.h>
#include "freqTreeNode.c"
#include "linkedList.c"
#include "freqTable.c"

typedef struct {
    LinkedList *list;
    NodeTree *root;
} FreqTree;

FreqTree *allocFreqTree(LinkedList *list) {
    FreqTree *l;
    l = (FreqTree *) malloc(sizeof(FreqTree));
    if (NULL != l) {
        l->list = list;
        l->root = NULL;
    }
    return l;
}

void insertInArray(NodeTree *nodeArray, )

void initiateFreqTree(FreqNode *root, FreqTree **tree) {
    


    // while not had ONE root
    while (NULL != root->next) {

    }
}