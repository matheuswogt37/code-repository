typedef struct sNodeTree {
    // to identify if is letter of just node that connect others (on slides it's called '+')
    char state;
    // the letter that node represents, if is just for connection than will be called '+', but can be possíble a node with letter + and being letter-node
    char let;
    int freq;
    struct sNodeTree *left;
    struct sNodeTree *right;
} NodeTree;