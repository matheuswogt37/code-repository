#include <stdio.h>
#include <stdlib.h>

typedef struct sNode
{
    int info;
    struct sNode *next;
} Node;

typedef struct
{
    struct sNode *head;
    struct sNode *tail;
    int size;
} List;
// ----------------------------------------------------------------------------------------

void errorTreatment(int cod)
{
    if (cod == -1)
    {
        printf("OVERFLOW\nNAO EH POSSIVEL ALOCAR MAIS MEMORIA\n\n");
    }
    else if (cod == -2)
    {
        printf("LISTA VAZIA\nNAO EH POSSIVEL REMOVER NODOS DE UMA LISTA VAZIA\n\n");
    }
    else if (cod == -3)
    {
        printf("IMPOSSIVEL REMOVER\nPIVO EH O ULTIMO NODO DA LISTA\n\n");
    }
}

Node *allocNode(int data)
{
    Node *nodo;
    nodo = (Node *)malloc(sizeof(Node));
    if (nodo != NULL)
    {
        nodo->info = data;
        nodo->next = NULL;
    }
    return nodo;
}

List *allocList()
{
    List *queue;
    queue = (List *)malloc(sizeof(List));
    if (queue != NULL)
    {
        queue->head = NULL;
        queue->tail = NULL;
    }
    queue->size = 0;
    return queue;
}

void freeList(List *queue)
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

int emptyList(List *list)
{
    if (list->size == 0)
    {
        return 1;
    }
    return 0;
}

int insertNode(List *list, Node *pivo, int data)
{
    Node *nodo;
    nodo = allocNode(data);

    if (nodo == NULL)
    {
        return -1;
    }
    if (pivo == NULL)
    {
        if (emptyList(list))
        {
            list->tail = nodo;
        }
        nodo->next = list->head;
        list->head = nodo;
    }
    else
    {
        if (pivo == list->tail)
        {
            list->tail = nodo;
        }
        nodo->next = pivo->next;
        pivo->next = nodo;
    }
    list->size++;
    return 1;
}

int removeNode(List *list, Node *pivo)
{
    Node *oldNodo;
    if (emptyList(list))
    {
        return -2; // lista vazia
    }
    if (pivo == NULL)
    {
        oldNodo = list->head;
        list->head = oldNodo->next;

        if (list->head == NULL)
        {
            list->tail = NULL;
        }
    }
    else
    {
        if (pivo->next == NULL)
        {
            return -3; // pivo eh o ultimo da lista
        }
        oldNodo = pivo->next;
        pivo->next = oldNodo->next;
        if (pivo->next == NULL)
        {
            list->tail = pivo;
        }
    }
    free(oldNodo);
    list->size--;
    return 1;
}

void printList(List *list)
{
    Node *nodo;
    if (emptyList(list))
    {
        printf("\nLista esta vazia!\n");
    }
    else
    {
        nodo = list->head;
        printf("\n<-- Lista -->\n");
        while (nodo != NULL)
        {
            printf("%i  ", nodo->info);
            nodo = nodo->next;
        }
    }
}