#include <stdio.h>
#include <stdlib.h>

typedef struct sNode
{
    int info;
    struct sNode *above;
    struct sNode *below;
} Node;

typedef struct
{
    Node *top;
    int size;
} Pile;

// createNode
Node *createNode(int data)
{
    Node *nodo;
    nodo = (Node *)malloc(sizeof(Node));
    if (nodo != NULL)
    {
        nodo->info = data;
        nodo->above = NULL;
        nodo->below = NULL;
    }

    return nodo;
}

// allocPile
Pile *allocPile()
{
    Pile *pile;
    pile = (Pile *)malloc(sizeof(Pile));
    if (pile != NULL)
    {
        pile->top = NULL;
        pile->size = 0;
    }
    return pile;
}

// freeNode
void freeNode(Node *nodo)
{
    free(nodo);
}

// freePile
void freePile(Pile *pile)
{
    Node *delNodo, *auxNodo;
    delNodo = pile->top;
    for (int i = 0; i < pile->size; i++)
    {
        auxNodo = delNodo->below;
        freeNode(delNodo);
        delNodo = auxNodo;
    }
    free(pile);
}

// errorTreatment
void errorTreatment(int error)
{
    if (error == -1)
    {
        printf("\nOVERFLOW\tmemoria insuficiente!\n");
    }
    else if (error == -2)
    {
        printf("\nPILHA VAZIA\tnao ha elementos na pilha!\n");
    }
}

// emptyPile
int emptyPile(Pile *pile)
{
    if (pile->size == 0)
    {
        return 1;
    }
    return 0;
}

// insertNode
int insertNode(Pile *pile, int data)
{
    Node *nodo;
    nodo = createNode(data);
    if (nodo == NULL)
    {
        return -1;
    }

    if (emptyPile(pile) == 0)
    {
        nodo->below = pile->top;
        pile->top->above = nodo;
    }
    pile->top = nodo;

    pile->size++;
    return 1;
}

// removeNode
int removeNode(Pile *pile)
{
    Node *auxNodo;
    if (emptyPile(pile))
    {
        return -2;
    }
    auxNodo = pile->top->below;
    auxNodo->above = NULL;
    freeNode(pile->top);
    pile->top = auxNodo;

    pile->size--;
    return 1;
}

// searchNode
int searchNode(Pile *pile, int data)
{
    Node *nodo;
    if (emptyPile(pile))
    {
        return -2;
    }
    nodo = pile->top;
    for (int count = pile->size; count > 0; count--)
    {
        if (nodo->info == data)
        {
            printf("Valor %i encontrado na posicao %i\n", nodo->info, count);
            return 1;
        }
        nodo = nodo->below;
    }

    printf("\nvalor %i nao encontrado\n", data);
    return 1;
}

// printPile
int printPile(Pile *pile)
{
    Node *nodo;
    if (emptyPile(pile))
    {
        return -2;
    }
    nodo = pile->top;

    printf("\n\tpilha - %i\n", pile->size);
    for (int i = 0; i < pile->size; i++)
    {
        printf("\t%i\n", nodo->info);
        nodo = nodo->below;
    }
    return 1;
}

void clearPile(Pile *pile) {
    Node *delNodo, *auxNodo;
    delNodo = pile->top;
    for (int i = 0; i < pile->size; i++) {
        auxNodo = delNodo->below;
        free(delNodo);
        delNodo = auxNodo;
    }
    pile->size = 0;
}