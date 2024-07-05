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
NodeTree *allocNodeTree(char state, char let, int freq) {
    NodeTree *node;
    node = (NodeTree *) malloc(sizeof(NodeTree));
    if (NULL != node) {
        node->isLetter = state;
        node->let = let;
        node->freq = freq;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

FreqTree *allocFreqTree() {
    FreqTree *node;
    node = (FreqTree *) malloc(sizeof(FreqTree));
    if (NULL != node) {
        node->list = NULL;
        node->root = NULL;
    } else {
        return NULL;
    }
    return node;
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
    freeFreqTreeRecursive(tree->root);
    //* free tree 
    free(tree);
}