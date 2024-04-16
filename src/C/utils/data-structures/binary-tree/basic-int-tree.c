#include <stdio.h>
#include <stdlib.h>

typedef struct sNode
{
    int key;
    struct sNode *father;
    struct sNode *right;
    struct sNode *left;
} Node;

// utils for alloc and free memory
Node *createNode(int info)
{
    Node *node;
    node = (Node *)malloc(sizeof(Node));
    if (node != NULL)
    {
        node->key = info;
        node->father = NULL;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void freeTree(Node *node)
{
    if (node->left != NULL)
    {
        freeTree(node->left);
    }
    if (node->right != NULL)
    {
        freeTree(node->right);
    }
    free(node);
}

// search with recursive function
Node *recSearchByInfo(Node *node, int info)
{
    if (node->key == info)
    {
        return node;
    }
    if (node->right != NULL)
    {
        if (info > node->key)
        {
            return recSearchByInfo(node->right, info);
        }
    }
    if (node->left != NULL)
    {
        return recSearchByInfo(node->left, info);
    }
    printf("Valor %d nao encontrado!\n", info);
    return NULL;
}

// search withour recursive
Node *searchByInfo(Node *source, int info)
{
    Node *aux;
    aux = source;
    while (aux != NULL)
    {
        if (aux->key == info)
        {
            return aux;
        }
        if (info > aux->key)
        {
            aux = aux->right;
        }
        else
        {
            aux = aux->left;
        }
    }
    printf("Valor %d nao encontrado!\n", info);
    return aux;
}

// insert node
void insertNodeByNode(Node *father, Node *node)
{
    if (node->key > father->key)
    {
        if (father->right == NULL)
        {
            father->right = node;
            node->father = father;
        }
        else
        {
            insertNodeByNode(father->right, node);
        }
    }
    else /* if (node->key < father->key) */
    {
        if (father->left == NULL)
        {
            father->left = node;
            node->father = father;
        }
        else
        {
            insertNodeByNode(father->left, node);
        }
    }
}

void insertNodeByInfo(Node *father, int info)
{
    Node *node;
    node = createNode(info);
    if (node != NULL)
    {
        insertNodeByNode(father, node);
    }
}

// minimum and maximum
Node *getMinimum(Node *node)
{
    if (node->left == NULL)
    {
        return node;
    }
    return getMinimum(node->left);
}

Node *getMaximum(Node *node)
{
    if (node->right == NULL)
    {
        return node;
    }
    return getMinimum(node->right);
}

// remove nodes
int removeNodeByInfo(Node *source, int info)
{
    Node *remNode;
    Node *aux = NULL;
    remNode = searchByInfo(source, info);
    if (remNode == NULL)
    {
        printf("Valor %d nao existe! Impossivel remover\n", info);
        return 0;
    }
    else
    {
        if (remNode->right == NULL && remNode->left != NULL)
        {
            aux = remNode->left;
            aux->father = remNode->father;
        }
        else if (remNode->right != NULL && remNode->left == NULL)
        {
            aux = remNode->right;
            aux->father = remNode->father;
        }
        else if (remNode->right != NULL && remNode->left != NULL)
        {
            aux = remNode->right;
            aux->father = remNode->father;
            if (remNode->left != NULL)
            {
                if (aux->left != NULL)
                {
                    insertNodeByNode(aux, remNode->left);
                }
                else
                {
                    aux->left = remNode->left;
                    remNode->left->father = aux;
                }
            }
        }

        if (remNode->father != NULL)
        {
            if (remNode->father->right == remNode)
            {
                remNode->father->right = aux;
            }
            else
            {
                remNode->father->left = aux;
            }
        }

        if (remNode == source)
        {
            free(remNode);
            *source = *aux;
        }
        else
        {
            free(remNode);
        }
        return 1;
    }
}

// transplant nodes
int transplantNodesByNodes(Node *source, Node *nodeReplaced, Node *nodeSwitch)
{
    Node *aux = NULL;

    if (nodeReplaced == NULL || nodeSwitch == NULL)
    {
        printf("Nodos nao encontrados! Transplante nao realizado\n");
        return 0;
    }

    if (nodeSwitch->right == NULL && nodeSwitch->left != NULL)
    {
        aux = nodeSwitch->left;
        aux->father = nodeSwitch->father;
    }
    else if (nodeSwitch->right != NULL && nodeSwitch->left == NULL)
    {
        aux = nodeSwitch->right;
        aux->father = nodeSwitch->father;
    }
    else if (nodeSwitch->right != NULL && nodeSwitch->left != NULL)
    {
        aux = nodeSwitch->right;
        aux->father = nodeSwitch->father;
        if (nodeSwitch->left != NULL)
        {
            if (aux->left != NULL)
            {
                insertNodeByNode(aux, nodeSwitch->left);
            }
            else
            {
                aux->left = nodeSwitch->left;
                nodeSwitch->left->father = aux;
            }
        }
    }

    if (nodeSwitch->father != NULL)
    {
        if (nodeSwitch->father->right == nodeSwitch)
        {
            nodeSwitch->father->right = aux;
        }
        else
        {
            nodeSwitch->father->left = aux;
        }
    }

    if (nodeSwitch == source)
    {
        *source = *aux;
    }

    nodeSwitch->left = nodeReplaced->left;
    nodeSwitch->right = nodeReplaced->right;
    nodeSwitch->father = nodeReplaced->father;

    if (nodeReplaced->father != NULL)
    {
        if (nodeReplaced->father->left = nodeReplaced)
        {
            nodeReplaced->father->left = nodeSwitch;
        }
        else
        {
            nodeReplaced->father->right = nodeSwitch;
        }
    }
    if (nodeReplaced->left != NULL)
    {
        nodeReplaced->left->father = nodeSwitch;
    }
    if (nodeReplaced->right != NULL)
    {
        nodeReplaced->right->father = nodeSwitch;
    }

    if (nodeReplaced == source)
    {
        free(nodeReplaced);
        *source = *nodeSwitch;
        printf("source - %d - %p\n", source->key, &source);
    }
    else
    {
        free(nodeReplaced);
    }

    return 1;
}

int transplantNodesByInfo(Node *source, int nodeReplaced, int nodeSwitch)
{
    Node *nReplaced = searchByInfo(source, nodeReplaced);
    Node *nSwitch = searchByInfo(source, nodeSwitch);
    return transplantNodesByNodes(source, nReplaced, nSwitch);
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
        insertNodeByInfo(source, test[i]);
    }

    printf("inOrder\n");
    printInOrder(source);
    printf("\n");

    removeNodeByInfo(source, 6);
    // transplantNodesByInfo(source, 6, 9);
    printf("source - %d - %p\n", source->key, &source);

    printf("inOrder\n");
    printInOrder(source);
    printf("\n");

    // TEST - search tree key
    // searchTreeKey(tree, 8);

    // TEST - prints
    // printf("inOrder\n");
    // printInOrder(source);
    // printf("\n");

    // printf("preOrder\n");
    // printPreOrder(source);
    // printf("\n");

    // printf("postOrder\n");
    // printPostOrder(source);
    // printf("\n");

    freeTree(source);
    return 0;
}