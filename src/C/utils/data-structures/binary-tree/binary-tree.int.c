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

Node *findFather(Node *source, Node *node)
{
    if (source == NULL || source->left == node || source->right == node)
    {
        return source;
    }
    if (node->key > source->key)
    {
        return findFather(source->right, node);
    }
    else
    {
        return findFather(source->left, node);
    }
}

// AVL

// right rotation
void rightRotation(Node **realSource, Node **oldNode, Node *newNode)
{
    Node *father = findFather(*realSource, (*oldNode));
    if (father != NULL) // oldNode->father->child = newNode
    {
        if (father->left == *oldNode)
        {
            father->left = newNode;
        }
        else
        {
            father->right = newNode;
        }
    }

    (*oldNode)->left = newNode->right;
    newNode->right = (*oldNode);

    if (*oldNode == *realSource) {
        *realSource = newNode;
        *oldNode = *realSource;
    }

}

// left rotation
void leftRotation(Node **realSource, Node **oldNode, Node *newNode)
{
    Node *father = findFather(*realSource, (*oldNode));
    if (father != NULL) // oldNode->father->child = newNode
    {
        if (father->left == *oldNode)
        {
            father->left = newNode;
        }
        else
        {
            father->right = newNode;
        }
    }

    (*oldNode)->right = newNode->left;
    newNode->left = *oldNode;

    if (*oldNode == *realSource)
    {
        *realSource = newNode;
        *oldNode = *realSource;
    }
}
// left left case
void LLCase(Node **realSource, Node **oldNode, Node *newNode)
{
    rightRotation(realSource, oldNode, newNode);
}

// right right case
void RRCase(Node **realSource, Node **oldNode, Node *newNode)
{
    leftRotation(realSource, oldNode, newNode);
}

// left right case
void LRCase(Node **realSource, Node **oldNode, Node *newNode)
{
    leftRotation(realSource, &newNode, newNode->right);
    rightRotation(realSource, oldNode, (*oldNode)->left);
}

// right left case
void RLCase(Node **realSource, Node **oldNode, Node *newNode)
{
    rightRotation(realSource, &newNode, newNode->left);
    leftRotation(realSource, oldNode, (*oldNode)->right);
}

// calc only height [return height, recursive function]
int calcOnlyHeight(Node *source)
{
    if (source == NULL)
    {
        return 0;
    }
    int actualyHeight, tempHeight;
    actualyHeight = tempHeight = 0;
    if (source->left != NULL)
    {
        actualyHeight = calcOnlyHeight(source->left);
    }
    if (source->right != NULL)
    {
        tempHeight = calcOnlyHeight(source->right);
    }
    if (tempHeight > actualyHeight)
    {
        return tempHeight + 1;
    }
    return actualyHeight + 1;
}

// calc greater height [1 - left, 2 - right]
int calcGreaterHeight(Node *source)
{
    int lHeight, rHeight;
    lHeight = rHeight = 0;
    if (source->left != NULL)
    {
        lHeight = calcOnlyHeight(source->left);
    }
    if (source->right != NULL)
    {
        rHeight = calcOnlyHeight(source->right);
    }
    if (lHeight > rHeight)
    {
        return 1;
    }
    return 2;
}

// calc balace factor

void calcBalanceFactor(Node **RealSource, Node *source)
{
    int leftHeight, rightHeight, balanceFactor, tempLHeight, tempRHeight;
    tempLHeight = tempRHeight = 0;

    leftHeight = calcOnlyHeight(source->left);
    rightHeight = calcOnlyHeight(source->right);
    balanceFactor = leftHeight - rightHeight;
    if (balanceFactor < -1)
    {
        if (source->right->left != NULL)
        {
            tempLHeight = calcOnlyHeight(source->right->left);
        }
        if (source->right->right != NULL)
        {
            tempRHeight = calcOnlyHeight(source->right->right);
        }
        if (tempLHeight > tempRHeight)
        {
            // case right - left
            RLCase(RealSource, &source, source->right);
        }
        else
        {
            // case right - right
            RRCase(RealSource, &source, source->right);
        }
    }
    else if (balanceFactor > 1)
    {
        // when right - ? give priority to source->left greater height if (source->left->left != NULL) // calc souce->right->left height
        {
            tempLHeight = calcOnlyHeight(source->left->left);
        }
        if (source->left->right != NULL) // calc souce->right->right height
        {
            tempLHeight = calcOnlyHeight(source->left->right);
        }
        if (tempRHeight > tempLHeight)
        {
            // case left - right
            LRCase(RealSource, &source, source->left);
        }
        else
        {
            // case left - left
            LLCase(RealSource, &source, source->left);
        }
    }
    if (source->left != NULL) {
        calcBalanceFactor(RealSource, source->left);
    }
    if (source->right != NULL) {
        calcBalanceFactor(RealSource, source->right);
    }
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

    // int test[] = {5, 9, 8, 4, 10};

    // Node *source = createNode(6);
    // int *height = 0;

    // for (int i = 0; i < 5; i++)
    // {
    //     source = insertNodeByInfo(source, test[i]);
    // }

    // printInOrder(source);
    // printf("\n");

    // // deleteNodeByNode(&source, searchNode(source, 6));

    // insertNodeByInfo(source, 3);
    // insertNodeByInfo(source, 2);
    // insertNodeByInfo(source, 1);
    // calcBalanceFactor(&source, source, height);

    // printInOrder(source);
    // printf("\n");

    // TESTES DE FUNCOES

    int test[] = {5, 9, 8, 4, 10};

    Node *source = createNode(6);

    for (int i = 0; i < 5; i++)
    {
        source = insertNodeByInfo(source, test[i]);
    }

    source = insertNodeByInfo(source, 3);
    source = insertNodeByInfo(source, 2);
    source = insertNodeByInfo(source, 1);


    printf("\nsource before calc- %i\n", source->key);
    calcBalanceFactor(&source, source);

    // LLCase(&source, &source, source->left);

    printInOrder(source);
    printf("\nsource after calc- %i\n", source->key);

    printf("terminado\n");

    return 0;
}