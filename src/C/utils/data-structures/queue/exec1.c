#include <stdio.h>
#include <stdlib.h>
#define arrayLength(array) (sizeof((array)) / sizeof((array)[0]))

typedef struct sNode
{
    struct sNode *next;
    struct sNode *prev;
    int info;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
    int size;
} List;

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

Node *createNode(int data)
{
    Node *nodo;
    nodo = (Node *)malloc(sizeof(Node));
    if (nodo != NULL)
    {
        nodo->next = NULL;
        nodo->prev = NULL;
        nodo->info = data;
        return nodo;
    }
    return NULL;
}

List *allocList()
{
    List *list;
    list = (List *)malloc(sizeof(List));
    if (list != NULL)
    {
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
        return list;
    }
    return NULL;
}

int emptyList(List *list)
{
    if (list->size == 0)
    {
        return 1;
    }
    return 0;
}

void freeList(List *list)
{
    Node *delNodo, *auxNodo;
    int i;
    delNodo = list->head;
    if (emptyList(list) == 0)
    {
        for (i = 0; i < list->size; i++)
        {
            auxNodo = delNodo->next;
            free(delNodo);
            delNodo = auxNodo;
        }
    }
    free(list);
}

int insertNodo(List *list, int data)
{
    Node *newNodo;
    newNodo = createNode(data);
    if (newNodo == NULL)
    {
        return -1; // error - overflow
    }
    if (emptyList(list))
    {
        list->head = newNodo;
        list->tail = newNodo;
    }
    else
    {
        newNodo->prev = list->tail;
        list->tail->next = newNodo;
        list->tail = newNodo;
    }
    list->size++;
    return 1;
}

int removeNode(List *list, int data)
{
    Node *delNodo;
    if (emptyList(list))
    {
        return -2; // - lista vazia
    }
    if ((list->tail->info + data) != 0)
    {
        return -3; // fechamento não confere, expressão inválida
    }
    delNodo = list->tail;
    list->tail = delNodo->prev;
    free(delNodo);
    list->size--;
    return 1;
}

int getCharValue(char character)
{
    if (character == '(')
    {
        return 1;
    }
    else if (character == ')')
    {
        return -1;
    }
    else if (character == '[')
    {
        return 2;
    }
    else if (character == ']')
    {
        return -2;
    }
    else if (character == '{')
    {
        return 3;
    }
    else if (character == '}')
    {
        return -3;
    }
    return 0;
}

void verifyInput(List *list, char input[50])
{
    int charNum, cond;
    cond = 1;
    int i = 0;
    while ((i < 50) && (cond == 1))
    {
        charNum = getCharValue(input[i]);
        if (charNum > 0)
        {
            cond = insertNodo(list, charNum);
        }
        else if (charNum < 0)
        {
            cond = removeNode(list, charNum);
        }
        i++;
    }
    if (list->size > 0) {
        cond = 0;
    }
    if (cond != 1)
    {
        printf("%s eh inválido\n", input);
    }
    else
    {
        printf("%s eh válido\n", input);
    }
}

int main()
{
    List *queue;
    queue = allocList();

    char inputs[5][50] = {{"(A + B} )"},
                          {"{[A + B] - [(C - D)]"},
                          {"(A + B)-{C + D}-[F+ G]"},
                          {"((H) * {([J + K])})"},
                          {"(((A))))"}};

    for (int j = 0; j < 5; j++)
    {
        verifyInput(queue, inputs[j]);
        freeList(queue);
        queue = allocList();
    }

    freeList(queue);
    printf("passou\n");
    return 0;
}