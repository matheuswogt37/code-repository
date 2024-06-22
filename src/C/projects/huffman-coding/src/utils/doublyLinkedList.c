#include <stdio.h>
#include <stdlib.h>

typedef struct sNode {
    char info;
    struct sNode *next;
    struct sNode *prev;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
    int size;
} List;

// ----------------------------------------------------------------------------------------

Node *createNode(char data) {
    Node *nodo;
    nodo = (Node *)malloc(sizeof(Node));
    if (nodo != NULL) {
        nodo->info = data;
        nodo->next = NULL;
        nodo->prev = NULL;
    }
    return nodo;
}

List *allocList() {
    List *queue;
    queue = (List *)malloc(sizeof(List));
    if (queue != NULL) {
        queue->head = NULL;
        queue->tail = NULL;
    }
    queue->size = 0;
    return queue;
}

void freeNode(Node *nodo) {
    free(nodo);
}

void freeList(List *queue) {
    Node *delNodo, *auxNodo;
    int i;
    delNodo = queue->head;
    auxNodo = NULL;
    for (i = 0; i < queue->size; i++) {
        auxNodo = delNodo->next;
        free(delNodo);
        delNodo = auxNodo;
    }
    freeNode(delNodo);
    if (NULL != auxNodo) {
        freeNode(auxNodo);
    }
    free(queue);
}

int emptyList(List *list) {
    if (list->size == 0) {
        return 1;
    }
    return 0;
}

int insertNode(List *list, Node *pivo, char data) {
    Node *newNodo;
    newNodo = createNode(data);
    if ((pivo == NULL) && (emptyList(list) == 0)) {
        return -1;
    }
    if (emptyList(list)) {
        list->head = newNodo;
        list->tail = newNodo;
    } else {
        newNodo->next = pivo->next;
        newNodo->prev = pivo;

        if (pivo->next == NULL) {
            list->tail = newNodo;
        } else {
            pivo->next->prev = newNodo;
        }
        pivo->next = newNodo;
    }
    list->size++;
    return 1;
}

int removeNode(List *list, Node *pivo) {
    if (emptyList(list)) {
        return -2;
    }
    if ((pivo != NULL)) {
        if (list->head == pivo) {
            list->head = pivo->next;
            if (list->head == NULL) {
                list->tail = NULL;
            } else {
                list->head->prev = NULL;
            }
        } else {
            pivo->prev->next = pivo->next;
            if (pivo->next == NULL) {
                list->tail = pivo->prev;
            } else {
                pivo->next->prev = pivo->prev;
            }
        }
        freeNode(pivo);
        list->size--;
        return 1;
    }
    return -3;
}

Node *searchInfo(List *list, char data) {
    int i;
    Node *nodo;
    nodo = list->head;
    for (i = 0; i < list->size; i++) {
        if (nodo->info == data) {
            return nodo;
        }
        nodo = nodo->next;
    }
    return NULL;
}

void printList(List *list) {
    Node *nodo;
    if (emptyList(list)) {
        printf("\nLista esta vazia!\n");
    } else {
        nodo = list->head;
        printf("\n<-- Lista -->\n");
        while (nodo != NULL) {
            printf("%c", nodo->info);
            nodo = nodo->next;
        }
    }
}

void errorTreatment(int error) {
    if (error == -1) {
        printf("Pivo null so aceito na primeira insercao!\n");
    } else if (error == -2) {
        printf("\nA lista estah vazia por isso nao podera ser retirado nenhum valor!\n");
    } else if (error == -3) {
        printf("\nO elemento informado nao foi encontrado! nenhum outro elemento foi removido\n");
    }
}

Node *search(List *list, char data) {
    Node *nodo;
    if (emptyList(list)) {
        return NULL;
    } else {
        nodo = list->head;
        while (nodo != NULL) {
            if (nodo->info == data) {
                return nodo;
            }
            nodo = nodo->next;
        }
    }
    return NULL;
}

void clearDoublyList(List *list) {
    Node *nodo, *auxNodo;
    nodo = list->head;
    while (nodo != NULL) {
        auxNodo = nodo->next;
        free(nodo);
        nodo = auxNodo;
    }
    list->size = 0;
}

void swapNodes(List *list, Node *nodo1, Node *nodo2) {
    Node *auxPrev, *auxNext;
    //  atribuição nos campos das listas
    if (nodo1 == list->head) {
        list->head = nodo2;
    } else if (nodo2 == list->head) {
        list->head = nodo1;
    }
    if (nodo1 == list->tail) {
        list->tail = nodo2;
    } else if (nodo2 == list->tail) {
        list->tail = nodo1;
    }

    //  troca dos elementos
    auxNext = nodo1->next;
    auxPrev = nodo1->prev;
    nodo1->next = nodo2->next;
    nodo1->prev = nodo2->prev;
    nodo2->next = auxNext;
    nodo2->prev = auxPrev;
}