#include<stdio.h>
#include<stdlib.h>

typedef struct sNode {
    int info;
    struct sNode *next;
    struct sNode *prev;
}Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
}List;

// ----------------------------------------------------------------------------------------

Node *createNode(int data) {
    Node *nodo;
    nodo = (Node *)malloc(sizeof(Node));
    if (nodo != NULL)
    {
        nodo->info = data;
        nodo->next = NULL;
        nodo->prev = NULL;
    }
    return nodo;
}

List *allocList() {
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

void freeNode(Node *nodo)
{
    free(nodo);
}

void freeList(List *queue)
{
    Node *delNodo, *auxNodo;
    int i;
    delNodo = queue->head;
    for (i = 0; i < queue->size; i++)
    {
        auxNodo = delNodo->next;
        free(delNodo);
        delNodo = auxNodo;
    }
    freeNode(delNodo);
    freeNode(auxNodo);
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

int insertNodo(List *list, Node *pivo, int data) {
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
    if (emptyList(list))
    {
        return -2;
    }
    if ((pivo!=NULL)) {
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

Node *searchInfo(List *list, int data) {
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

void printList(List *list)
{
    Node *nodo;
    if (emptyList(list))
    {
        printf("Lista esta vazia!\n");
    }
    else
    {
        nodo = list->head;
        printf("<-- Lista -->\n");
        while (nodo != NULL)
        {
            printf("%i  ", nodo->info);
            nodo = nodo->next;
        }
    }
}

void errorTreatment(int error)
{
    if (error == -1)
    {
        printf("Pivo null so aceito na primeira insercao!\n");
    }
    else if (error == -2)
    {
        printf("\nA lista estah vazia por isso nao podera ser retirado nenhum valor!\n");
    }
    else if (error == -3)
    {
        printf("\nO elemento informado nao foi encontrado! nenhum outro elemento foi removido\n");
    }
}

Node *search(List *list, int data)
{
    Node *nodo;
    if (emptyList(list))
    {
        return NULL;
    }
    else
    {
        nodo = list->head;
        while (nodo != NULL)
        {
            if (nodo->info == data)
            {
                return nodo;
            }
            nodo = nodo->next;
        }
    }
    return NULL;
}

void commands(List *list) {
    int data, dataPivo, cmd, cmd2;
    do
    {
        printf("\n<-- Escolha -->\n");
        printf("1 - inserir elemento\n2 - remover elemento\n3 - mostrar a lista\n0 - sair\n");
        scanf("%i", &cmd);
        if (cmd == 1) // inserir elemento
        {
            printf("Digite a informacao a ser armazenada: ");
            scanf("%i", &data);
            printf("\n[ ESCOLHA ]\n");
            printf("1 - pivo proprio\n2 - elemento head\n3 - elemento tail\n");
            scanf("%i", &cmd2);
            if (cmd2 == 1)
            {
                printf("Digite a informacao referente ao pivo: ");
                scanf("%i", &dataPivo);
                insertNodo(list, searchInfo(list, dataPivo), data);
            }
            else if (cmd2 == 2)
            {
                insertNodo(list, list->head, data);
            }
            else if (cmd2 == 3)
            {
                insertNodo(list, list->tail, data);
            }
            else
            {
                printf("Escolha nao valida!\n");
            }
        }
        else if (cmd == 2) // remover elemento
        {
            printf("Digite a informacao referente ao pivo: ");
            scanf("%i", &dataPivo);
            errorTreatment(removeNode(list, search(list, dataPivo)));
        }
        else if (cmd == 3) // percorrer a lista
        {
            printList(list);
        }
    } while (cmd != 0);
    printf("saindo...");
}