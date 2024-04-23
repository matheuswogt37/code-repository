#include <stdio.h>
#include <stdlib.h>

typedef struct sNode
{
    struct sNode *left;
    struct sNode *right;
    int key;
} Node;

// utils
Node *createNode(int info)
{
    Node *node;
    node = (Node *)malloc(sizeof(Node));
    if (node != NULL)
    {
        node->left = NULL;
        node->right = NULL;
        node->key = info;
    }

    return node;
}

void freeNode(Node *node)
{
    free(node);
}

void freeTree(Node *source)
{
    if (source->left != NULL)
    {
        freeNode(source->left);
    }
    if (source->right != NULL)
    {
        freeNode(source->right);
    }
    freeNode(source);
}

Node *searchNode(Node *source, int info)
{
    if (source == NULL || source->key == info)
    {
        return source;
    }
    if (source->right != NULL && info >= source->key)
    {
        return searchNode(source->right, info);
    }
    else
    {
        return searchNode(source->left, info);
    }
}

Node *iterativeSearchNode(Node *source, int info)
{
    while (source != NULL && source->key != info)
    {
        if (info >= source->key)
        {
            source = source->right;
        }
        else
        {
            source = source->left;
        }
    }
    return source;
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

// insert
Node *insertNodeByInfo(Node *source, int info)
{
    if (source == NULL)
    {
        return createNode(info);
    }
    if (info >= source->key)
    {
        source->right = insertNodeByInfo(source->right, info);
    }
    else
    {
        source->left = insertNodeByInfo(source->left, info);
    }
    return source;

}

// find father
Node *findFather(Node *source, Node *node)
{
    if (source == NULL || source->left == node || source->right == node) {
        return source;
    }
    if (node->key > source->key) {
        return findFather(source->right, node);
    } else {
        return findFather(source->left, node);
    }
}

// transplant
void transplantNodeByNodes(Node **source, Node *nodeReplaced, Node *nodeSwitch)
{
    Node *father = findFather(*source, nodeReplaced);
    if (father == NULL) // if is the source
    {
        *source = nodeSwitch;
    }
    else if (father->right == nodeReplaced)
    {
        father->right = nodeSwitch;
    }
    else
    {
        father->left = nodeSwitch;
    }
}

// delete
void deleteNodeByNode(Node **source, Node *delNode)
{
    Node *aux;
    if (delNode->right == NULL)
    {
        transplantNodeByNodes(source, delNode, delNode->left);
    }
    else if (delNode->left == NULL)
    {
        transplantNodeByNodes(source, delNode, delNode->right);
    }
    else
    {
        aux = getMinimum(delNode->right);
        if (aux != delNode->right)
        {
            transplantNodeByNodes(source, aux, aux->right);
            aux->right = delNode->right;
        }
        transplantNodeByNodes(source, delNode, aux);
        aux->left = delNode->left;
    }
    free(delNode);
}

// prints
void printInOrder(Node *node)
{
    if (node != NULL)
    {
        printInOrder(node->left);
        printf("%d ", node->key);
        printInOrder(node->right);
    }
}

void printPreOrder(Node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->key);
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}

void printPostOrder(Node *node)
{
    if (node != NULL)
    {
        printPostOrder(node->left);
        printPostOrder(node->right);
        printf("%d ", node->key);
    }
}

int main()
{
    int test[] = {5, 9, 8, 4, 10};

    Node *source = createNode(6);

    for (int i = 0; i < 5; i++)
    {
        source = insertNodeByInfo(source, test[i]);
    }

    printInOrder(source);
    printf("\n");   

    deleteNodeByNode(&source, searchNode(source, 6));

    printInOrder(source);
    printf("\n");

    return 0;
}