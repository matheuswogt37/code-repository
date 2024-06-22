#include <stdio.h>
#include <stdlib.h>
#include "freqTreeNode.c"
#include "linkedList.c"
#include "freqTable.c"

typedef struct {
    //* all frequency nodes are here
    LinkedList *list;
    //* the final root, only defined when the list has only one node
    NodeTree *root;
} FreqTree;

//* alloc nodeTree
NodeTree *allocNodeTree(char state, char let) {
    NodeTree *node;
    node = (NodeTree *) malloc(sizeof(NodeTree));
    if (NULL != node) {
        node->state = state;
        node->let = let;
        node->freq = 1;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

FreqTree *allocFreqTree() {
    FreqTree *tree;
    tree = (FreqTree *) malloc(sizeof(FreqTree));
    if (NULL != tree) {
        tree->list = allocLinkedList();
        tree->root = NULL;
    }
}

void freeFreqTreeRecursive(NodeTree *root) {
    if (NULL != root->left) {
        freeFreqTreeRecursive(root->left);
    }
    if (NULL != root->right) {
        freeFreqTreeRecursive(root->right);
    }

    free(root);
}

void freeFreqTree(FreqTree *tree) {
    //* free list
    freeLinkedList(tree->list);
    //* free root
    freeFreqTreeRecursive(tree);
    //* free tree 
    free(tree);
}







void setList(FreqTree **tree, FreqNode *table) {
    FreqNode *aux;

    aux = table;
    while (NULL != aux) {
        // insertNodeLinkedList((*tree)->list, (*tree)->list->tail, );
        aux = aux->next;
    }
}

void initFreqTree(FreqTree **tree, FreqNode *table) {
    //* set freq tree list

    //*
}