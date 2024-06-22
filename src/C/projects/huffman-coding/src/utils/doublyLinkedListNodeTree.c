#include <stdio.h>
#include <stdlib.h>

#include "freqTreeNode.c"

typedef struct sNodeListTree {
    NodeTree *info;
    struct sNodeListTree *next;
} NodeListTree;

// ----------------------------------------------------------------------------------------
NodeListTree *allocNodeListTree(NodeTree *i) {
    NodeListTree *node;
    node = (NodeListTree *)malloc(sizeof(NodeListTree));
    if (NULL != node) {
        node->info = i;
        node->next = NULL;
    }
    return node;
}

void freeListTree(NodeListTree *root) {
    NodeListTree *aux;
    while (NULL != root) {
        aux = root->next;
        free(root);
        root = aux;
    }
}

void insertListTreeByData(NodeListTree **root, NodeTree *data) {
    NodeListTree *node, *aux, *prev;
    node = allocNodeListTree(data);
    if (NULL != *root) {
        *root = data;
    } else {
        aux = *root;
        prev = NULL;
        while (data->freq < aux->info->freq) {
            prev = aux;
            aux = aux->next;
        }
        if (NULL != prev) {
            prev->next = node;
        }
        node->next = aux;
    }
}

NodeListTree *findPrev(NodeListTree *root, NodeListTree *data) {
    NodeListTree *aux;
    aux = root;
    if (NULL != aux) {
        if (data != aux) {
            while ((NULL != aux->next) && (data != aux->next)) {
                aux = aux->next;
            }
        }
    }

    return aux;
}

void insertListTreeByNode(NodeListTree **root, NodeListTree *node) {
    NodeListTree *aux, *prev;
    aux = *root;
    while (node->info->freq < aux->info->freq) {
        prev = aux;
        aux = aux->next;
    }
}

void removeListTree(NodeListTree **root, NodeListTree *data) {
    NodeListTree *prev;
    prev = findPrev(*root, data);
    if (NULL != prev) {
        prev->next = data->next;
    }
    if (data == root) {
        root = data->next;
    }
}