#include <stdio.h>
#include <stdlib.h>

typedef struct sNode
{
    int info;
    struct sNode *next;
    struct sNode *prev;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
    int size;
} Queue;

Queue *allocQueue()
{
    Queue *queue;
    queue = (Queue *)malloc(sizeof(Queue));

    if (queue != NULL)
    {
        queue->head = NULL;
        queue->tail = NULL;
        queue->size = 0;
    }

    return queue;
}

Node *allocNode(int data)
{
    Node *nodo;
    nodo = (Node *)malloc(sizeof(Node));

    if (nodo != NULL)
    {
        nodo->next = NULL;
        nodo->prev = NULL;
        nodo->info = data;
    }

    return nodo;
}

void freeNode(Node *nodo)
{
    free(nodo);
}

void freeQueue(Queue *queue)
{
    Node *delNodo, *auxNodo;

    delNodo = queue->head;
    for (int i = 0; i < queue->size; i++)
    {
        auxNodo = delNodo->next;
        free(delNodo);
        delNodo = auxNodo;
    }
    free(queue);
}

void errorTreatment(int error)
{
    if (error == -1)
    {
        printf("\nOVERFLOW\tmemoria insuficiente!\n");
    }
    else if (error == -2)
    {
        printf("\nFila vazia!\n");
    }
}

int emptyQueue(Queue *queue)
{
    if (queue->size == 0)
    {
        return 1;
    }
    return 0;
}

int insertNode(Queue *queue, int data)
{
    Node *nodo;
    nodo = allocNode(data);
    if (nodo == NULL)
    {
        return -1;
    }

    if (emptyQueue(queue))
    {
        queue->head = nodo;
    }
    else
    {
        nodo->prev = queue->tail;
        queue->tail->next = nodo;
    }
    queue->tail = nodo;
    queue->size++;
    return 1;
}

int removeNode(Queue *queue)
{
    Node *delNodo;
    if (emptyQueue(queue))
    {
        return -2;
    }
    delNodo = queue->head;
    if (queue->size != 1)
    {
        queue->head->next->prev = NULL;
    }
    queue->head = delNodo->next;
    free(delNodo);
    queue->size--;
    return 1;
}

int searchNode(Queue *queue, int data)
{
    Node *nodo;
    if (emptyQueue(queue))
    {
        return -2;
    }
    nodo = queue->head;
    for (int i = 0; i < queue->size; i++) {
        if (nodo->info == data) {
            printf("\nvalor %i encontrado na posicao %i\n", data, (i+1));
            return 1;
        }
        nodo = nodo->next;
    }

    printf("\nvalor %i nao encontrado\n", data);
    return 1;
}

int printQueue(Queue *queue) {
    Node *nodo;
    if (emptyQueue(queue)) {
        return -2;
    }
    nodo = queue->head;
    printf("\n\tfila - \n\t");



    for (Node *nodo = queue->head; nodo != NULL; nodo = nodo->next) {
        printf("%i  ", nodo->info);
    }

    return 1;
}