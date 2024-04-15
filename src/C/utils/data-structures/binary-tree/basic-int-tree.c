#include <stdio.h>
#include <stdlib.h>

typedef struct  sNode
{
    int key;
    struct sNode *father;
    struct sNode *right;
    struct sNode *left;
} Node;

typedef struct 
{
    Node *source;
} Binary_tree;

Node *createNode(int info) {
    Node *node;
    node = (Node *) malloc(sizeof(Node));
    if (node != NULL) {
        node->key = info;
        node->father = NULL;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

Binary_tree *createBinaryTree() {
    Binary_tree *tree;
    tree = (Binary_tree *) malloc(sizeof(Binary_tree));
    if (tree != NULL) {
        tree->source = NULL;
    }
    return tree;
}

void freeNode(Node *node) {
    if (node->left != NULL) {
        freeNode(node->left);
    }
    if (node->right != NULL) {
        freeNode(node->right);
    }
    free(node);
}

void freeBinaryTree(Binary_tree *tree) {
    if (tree->source != NULL) {
        freeNode(tree->source);
    }
    free(tree);
}

void insertNodeInTree(Node *father, Node *node) {
    if (node->key > father->key) {
        if (father->right == NULL) {
            father->right = node;
            node->father = father;
        } else {
            insertNodeInTree(father->right, node);
        }
    } else /* if (node->key < father->key) */ {
        if (father->left == NULL) {
            father->left = node;
            node->father = father;
        } else {
            insertNodeInTree(father->left, node);
        }
    }
}

void insertNode(Binary_tree *tree, int info) {
    Node *node = createNode(info);
    if (tree->source == NULL) {
        tree->source = node;
    } else {
        insertNodeInTree(tree->source, node);
    }
}


void printInOrder(Node *node) {
    if (node != NULL) {
        printInOrder(node->left);
        printf("%d ", node->key);
        printInOrder(node->right);
    }
}

void printPreOrder(Node *node) {
    if (node != NULL) {
        printf("%d ", node->key);
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}

void printPostOrder(Node *node) {
    if (node != NULL) {
        printPostOrder(node->left);
        printPostOrder(node->right);
        printf("%d ", node->key);
    }
}


int main() {
    int test[] = {6, 5, 7, 4, 8};
    Binary_tree *tree = createBinaryTree();

    for (int i = 0; i < 5; i++) {
        insertNode(tree, test[i]);
    }

    printf("inOrder\n");
    printInOrder(tree->source);
    printf("\n");
    
    printf("preOrder\n");
    printPreOrder(tree->source);
    printf("\n");
    
    printf("postOrder\n");
    printPostOrder(tree->source);
    printf("\n");
    

    freeBinaryTree(tree);
    return 0;
}