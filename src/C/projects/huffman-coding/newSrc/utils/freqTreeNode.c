#pragma once
//* my bool lib
#define bool int
#define true 1
#define false 0

typedef struct sNodeTree {
    //* to identify if is letter of just node that connect others (on slides it's called '+')
    //* 1 to letter, 0 to father (+)
    bool isLetter;
    //* the letter that node represents, if is just for connection than will be called '+', but can be possíble a node with letter + and being letter-node
    char let;
    int freq;
    struct sNodeTree *left;
    struct sNodeTree *right;
} NodeTree;