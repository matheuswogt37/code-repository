#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define RED true
#define BLACK false

typedef struct sNode
{
    struct sNode *left;
    struct sNode *right;
    struct sNode *father;
    int key;
    bool color;
} Node;

Node *createNode(int i);
void freeTreeRecursive(Node *source);
void freeTreeIterative(Node *source);
void leftRotate(Node **source, Node *x);
void rightRotate(Node **source, Node *x);
Node *getMinimum(Node *source);
Node *getMaximum(Node *source);
void transplant(Node **source, Node *u, Node *v);
void deleteFix(Node **source, Node *x);
void remove(Node **source, Node *z);
void fixInsertColor(Node **source, Node *n);
Node *insertRecursive(Node *source, int i);
void insertIterative(Node **source, int i);

// main for tests

Node *createNode(int i)
{
    Node *n;
    n = (Node *)malloc(sizeof(Node));
    if (NULL != n)
    {
        n->left = NULL;
        n->right = NULL;
        n->father = NULL;
        n->color = RED;
        n->key = i;
    }
    return n;
}

void freeTreeRecursive(Node *source)
{
    if (NULL != source->left)
    {
        freeTreeRecursive(source->left);
    }
    if (NULL != source->right)
    {
        freeTreeRecursive(source->right);
    }
    free(source);
}

void freeTreeIterative(Node *source)
{
    Node *aux;
    aux = source;
    while (NULL != source)
    {
        while (NULL != source->left)
        {
            source = source->left;
        }
        while (NULL != source->right)
        {
            source = source->right;
        }
        aux = source->father;
        free(source);
        source = aux;
    }
}

void leftRotate(Node **source, Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    if (NULL != y->left)
    {
        y->left->father = x;
    }
    y->father = x->father;
    if (NULL == x->father)
    {
        (*source) = y;
    }
    else if (x == x->father->left)
    {
        x->father->left = y;
    }
    else
    {
        x->father->right = y;
    }
    y->left = x;
    x->father = y;
}

void rightRotate(Node **source, Node *x)
{
    Node *y = x->left;
    x->left = y->right;
    if (NULL != y->right)
    {
        y->right->father = x;
    }
    y->father = x->father;
    if (NULL == x->father)
    {
        (*source) = y;
    }
    else if (x == x->father->left)
    {
        x->father->right = y;
    }
    else
    {
        x->father->left = y;
    }
    y->right = x;
    x->father = y;
}

Node *getMinimum(Node *source)
{
    if (source->left == NULL)
    {
        return source;
    }
    return getMinimum(source->left);
}

Node *getMaximum(Node *source)
{
    if (source->right == NULL)
    {
        return source;
    }
    return getMaximum(source->right);
}

void transplant(Node **source, Node *u, Node *v)
{
    if (NULL == u->father)
    {
        (*source) = v;
    }
    else if (u == u->father->left)
    {
        u->father->left = v;
    }
    else
    {
        u->father->right = v;
    }
    v->father = u->father;
}

void deleteFix(Node **source, Node *x) {

}

void remove(Node **source, Node *z)
{
    Node *y, *x;
    y = z;
    bool yDefaultColor = y->color;
    if (NULL == z->left)
    {
        x = z->right;
        transplant(source, z, z->right);
    }
    else if (NULL == z->right)
    {
        x = z->left;
        transplant(source, z, z->left);
    }
    else
    {
        y = getMinimum(z->right);
        yDefaultColor = y->color;
        x = y->right;
        if (y != z->right)
        {
            transplant(source, y, y->right);
            y->right = z->right;
            y->right->father = y;
        }
        else
        {
            x->father = y;
        }
        transplant(source, z, y);
        y->left = z->left;
        y->left->father = y;
        y->color = z->color;
    }
    if (yDefaultColor == BLACK) {
        deleteFix(source, x);
    }
}

void fixInsertColor(Node **source, Node *n)
{
    Node *y;
    while (n->color == RED)
    {
        if (n->father == n->father->father->left)
        {
            y = n->father->father->right;
            if (y->color == RED)
            {
                n->father->color = BLACK;
                y->color = BLACK;
                n->father->father->color = RED;
                n = n->father->father;
            }
            else
            {
                if (n == n->father->right)
                {
                    n = n->father;
                    leftRotate(source, n);
                }
                n->father->color = BLACK;
                n->father->father->color = RED;
                rightRotate(source, n->father->father);
            }
        }
        else
        {
            y = n->father->father->left;
            if (y->color == RED)
            {
                n->father->color = BLACK;
                y->color = BLACK;
                n->father->father->color = RED;
                n = n->father->father;
            }
            else
            {
                if (n == n->father->left)
                {
                    n = n->father;
                    rightRotate(source, n);
                }
                n->father->color = BLACK;
                n->father->father->color = RED;
                leftRotate(source, n->father->father);
            }
        }
    }
    (*source)->color = BLACK;
}

void insertIterative(Node **source, int i)
{
    Node *n;
    Node *aux, *fatAux;

    n = createNode(i);
    if (NULL != n)
    {
        aux = (*source);
        if (NULL != source)
        {
            fatAux = (*source)->father;
            // run while until find the slot 'aux' that n will replace
            while (NULL != aux)
            {
                if (i > aux->key)
                {
                    fatAux = aux;
                    aux = aux->right;
                }
                else
                {
                    fatAux = aux;
                    aux = aux->left;
                }
            }
            // rearage father children address
            if (i > fatAux->key)
            {
                fatAux->right = n;
            }
            else
            {
                fatAux->left = n;
            }
        }
        else // if alredy empty
        {
            source = n;
        }
        fixInsertColor(source, &n);
    }
    else // log if n equal null
    {
        printf("\n");
        printf("n equal null\n");
    }
}