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
    freeFreqTreeRecursive(tree->root);
    //* free tree 
    free(tree);
}

void createFreqTreeListNodeByData(FreqTree **tree, char let, int freq, bool state, NodeTree *left, NodeTree *right) {
    NodeTree *nodeTree;
    nodeTree = allocNodeTree(state, let, freq);
    nodeTree->left = left;
    nodeTree->right = right;
    insertNodeLinkedList((*tree)->list, nodeTree);
}

void createFreqTreeListNode(FreqTree **tree, FreqNode *node, bool state, NodeTree *left, NodeTree *right) {
    NodeTree *nodeTree;
    nodeTree = allocNodeTree(state, node->let, node->freq);
    nodeTree->left = left;
    nodeTree->right = right;
    insertNodeLinkedList((*tree)->list, nodeTree);
}

void initFreqTreeList(FreqTree **tree, FreqNode *table) {
    FreqNode *auxTable;

    //* foreach table to insert on list
    auxTable = table;
    while (NULL != auxTable) {
        createFreqTreeListNode(tree, auxTable, true, NULL, NULL);
    }
}

//* create a father nodeTree and insert into list
void insertIntoFreqTreeList(FreqTree **tree, LinkedNode *left, LinkedNode *right) {
    int freq;
    //* calc frequency to new father
    freq = left->nodeTree->freq + right->nodeTree->freq;
    
    //* create and insert on list
    createFreqTreeListNodeByData(tree, '+', freq, 0, left->nodeTree, right->nodeTree);
}

void populateFreqTree(FreqTree **tree) {
    LinkedNode *auxList, *auxListNext;
    auxList = (*tree)->list->head;

    //* while list had more than one element    
    while (NULL != auxList->next) {
        //* remove the first two elements
        auxListNext = auxList->next;
        remNodeLinkedList((*tree)->list, auxList);
        remNodeLinkedList((*tree)->list, auxListNext);

        //* create a father node and insert
        insertIntoFreqTreeList(tree, auxList, auxListNext);    

        //* free on list elements that will not be used anymore, ONLY THE LIST NODE NOT THE FREQ NODE
        free(auxList);
        free(auxListNext);

        //* reset the auxList to first element
        auxList = (*tree)->list->head;
    }
    //* set first list element as tree root
    (*tree)->root = (*tree)->list->head->nodeTree;
}

void initFreqTree(FreqTree **tree, FreqNode *table) {
    //* set freq tree list
    initFreqTreeList(tree, table);
    //* populate freq tree
    
}