// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct sNode
{
    struct sNode *next;
    int key;
} Node;

Node *createNode(int k)
{
    Node *n;
    n = (Node *)malloc(sizeof(Node));
    if (NULL != n)
    {
        n->next = NULL;
        n->key = k;
    }
    return n;
}

void freeList(Node *source)
{
    Node *aux;
    while (NULL != source)
    {
        aux = source->next;
        free(source);
        source = aux;
    }
}

void insertList(Node **source, Node **lastNode, int k)
{
    Node *n = createNode(k);
    Node *aux;
    if (NULL != n)
    {
        aux = (*source);
        if (NULL != aux)
        {
            while (NULL != aux->next)
            {
                aux = aux->next;
            }
            aux->next = n;
        }
        else
        {
            (*source) = n;
        }
        (*lastNode) = n;
    }
}

void printList(Node *s, Node *last)
{
    printf("---------------------------------------------------------------\n");
    if (NULL != s && NULL != last)
    {
        printf("source = %i                  List                lastNode = %i\n", s->key, last->key);
    }
    else
    {
    printf("                        List                                   \n");
    }
    while (NULL != s)
    {
        printf("%i ", s->key);
        s = s->next;
    }
    printf("\n");
    printf("---------------------------------------------------------------\n");
    printf("\n");
}

int main()
{
    Node *source = NULL;
    Node *lastNode = NULL;
    insertList(&source, &lastNode, 1);
    insertList(&source, &lastNode, 2);
    insertList(&source, &lastNode, 3);
    insertList(&source, &lastNode, 4);
    insertList(&source, &lastNode, 5);

    printList(source, lastNode);

    return 0;
}