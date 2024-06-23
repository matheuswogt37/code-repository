#include <stdio.h>
#include <stdlib.h>

#include "freqTreeNode.c"

typedef struct sLinkedNode {
    NodeTree *nodeTree;
    struct sLinkedNode *next;
    struct sLinkedNode *prev;
} LinkedNode;

typedef struct
{
    LinkedNode *head;
    LinkedNode *tail;
    int size;
} LinkedList;
// ----------------------------------------------------------------------------------------

LinkedNode *allocNode(NodeTree *data) {
    LinkedNode *nodo;
    nodo = (LinkedNode *)malloc(sizeof(LinkedNode));
    if (NULL != nodo) {
        nodo->nodeTree = data;
        nodo->next = NULL;
        nodo->prev = NULL;
    }
    return nodo;
}

LinkedList *allocLinkedList() {
    LinkedList *queue;
    queue = (LinkedList *)malloc(sizeof(LinkedList));
    if (NULL != queue) {
        queue->head = NULL;
        queue->tail = NULL;
    }
    queue->size = 0;
    return queue;
}

void freeLinkedList(LinkedList *queue) {
    free(queue);
}

void insertNodeLinkedList(LinkedList *queue, NodeTree *data) {
    LinkedNode *node, *aux;
    node = allocNode(data);
    if (NULL == queue->head) {
        queue->head = node;
        queue->tail = node;
    } else {
        aux = queue->head;
        // while to set aux the 'prev' position that data will be placed
        if (data->freq < aux->nodeTree->freq) {
            queue->head = node;
            node->next = aux;
            aux->prev = node;
        } else {
            while (NULL != aux->next && data->freq >= aux->next->nodeTree->freq) {
                aux = aux->next;
            }
            aux->next->prev = node;
            node->next = aux->next;
            node->prev = aux;
            aux->next = node;
        }
    }
}

void remNodeLinkedList(LinkedList *queue, LinkedNode *node) {
    LinkedNode *aux;
    
    node->next->prev = node->prev;
    node->prev->next = node->next;

    if (node == queue->head) {
        queue->head = node->next;
    }
    if (node == queue->tail) {
        queue->tail = node->prev;
    }

    free(node);
}