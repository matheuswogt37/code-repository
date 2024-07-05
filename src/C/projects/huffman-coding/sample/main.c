#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//* DIFERENCES BETWEEN WIN AND LINUX START

#ifdef __unix__
void set_OS_locale() {
    setlocale(LC_ALL, "");
}
#elif defined(_WIN32) || defined(WIN32)
void set_OS_locale() {
    setLocale(LC_ALL, "");
}
#endif

//* DIFERENCES BETWEEN WIN AND LINUX END

//* MACROS
#define ASCII_SIZE 256

//* GENERAL FUNCTIONS START
//* GENERAL FUNCTIONS END

//* FREQ_TABLE FUNCTIONS START

void fill_freq_table(FILE *file, unsigned int table[ASCII_SIZE]) {
    for (char ch = fgetc(file); EOF != ch; ch = fgetc(file)) {
        table[ch]++;
    }
    fseek(file, 0, SEEK_SET);
}

//* FREQ_TABLE FUNCTIONS END

//* NODE_TREE START
typedef struct sNode_tree {
    unsigned char let;
    unsigned int freq;
    struct sNode_tree *left, *right;
} Node_tree;

Node_tree *alloc_node_tree(unsigned char let, unsigned int freq) {
    Node_tree *node;
    node = (Node_tree *)malloc(sizeof(Node_tree));
    if (NULL != node) {
        node->let = let;
        node->freq = freq;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void free_node_tree(Node_tree *node) {
    free(node);
}

//* NODE_TREE END

//* NODE_LIST START

typedef struct sNode_list {
    Node_tree *info;
    struct sNode_list *next;
} Node_list;

Node_list *alloc_node_list(unsigned char let, unsigned int freq) {
    Node_list *node;
    node = (Node_list *)malloc(sizeof(Node_list));
    if (NULL != node) {
        node->info = alloc_node_tree(let, freq);
        node->next = NULL;
    }
    return node;
}

//* NODE_LIST END

//* HUFFMAN_TREE START

typedef struct {
    Node_list *root_list;
    Node_tree *root_tree;
} Huffman_tree;

Huffman_tree *alloc_huffman() {
    Huffman_tree *tree;
    tree = (Huffman_tree *)malloc(sizeof(Huffman_tree));
    if (NULL != tree) {
        tree->root_list = NULL;
        tree->root_tree = NULL;
    }
    return tree;
}

void free_huffman_list(Node_list *root) {
    Node_list *aux;
    while (NULL != root) {
        aux = root->next;
        free(root);
        root = aux;
    }
}

void free_huffman_tree(Node_tree *root) {
    if (NULL != root->left) {
        free_huffman_tree(root->left);
    }
    if (NULL != root->right) {
        free_huffman_tree(root->right);
    }
    free(root);
}

void insert_huffman_list(Node_list **root, Node_list *node) {
    Node_list *aux, *aux_aux;
    aux = (*root);

    if (NULL == aux) {
        (*root) = node;
    } else {
        aux_aux = NULL;
        while ((aux->info->freq <= node->info->freq)) {
            aux_aux = aux;
            aux = aux->next;
            if (NULL == aux) {
                break;
            }
        }
        if (NULL == aux_aux) {
            node->next = (*root);
            (*root) = node;
        } else {
            aux_aux->next = node;
            node->next = aux;
        }
    }
}

void remove_huffman_list(Node_list **root, Node_list *rem_node) {
    Node_list *aux, *aux_aux;
    aux_aux = NULL;
    aux = (*root);
    while (aux != rem_node) {
        aux_aux = aux;
        aux = aux->next;
    }

    if (NULL == aux_aux) {
        (*root) = aux->next;
    } else {
        aux_aux->next = aux->next;
    }
    //* this free only the node_list. The node_tree continues to exist
    //! ERROR this is wrong and i dont kwon why
    // free(rem_node);
}

void init_huffman_list(Node_list **root, unsigned int table[ASCII_SIZE]) {
    Node_list *node;
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (0 < table[i]) {
            node = alloc_node_list((unsigned char)i, table[i]);
            insert_huffman_list(root, node);
        }
    }
}

void insert_huffman_tree(Huffman_tree *huffman) {
    Node_list *node_list, *aux_list;
    int freq;

    aux_list = huffman->root_list;
    while (NULL != aux_list->next) {
        freq = aux_list->info->freq + aux_list->next->info->freq;
        node_list = alloc_node_list('+', freq);
        node_list->info->left = aux_list->info;
        remove_huffman_list(&aux_list, aux_list);
        node_list->info->right = aux_list->info;
        remove_huffman_list(&aux_list, aux_list);
        insert_huffman_list(&aux_list, node_list);
    }
    huffman->root_tree = aux_list->info;
    free_huffman_list(huffman->root_list);
}

void init_huffman_tree(Huffman_tree *huffman, unsigned int table[ASCII_SIZE]) {
    init_huffman_list(&huffman->root_list, table);
    insert_huffman_tree(huffman);
}

unsigned int get_depth_tree(Node_tree *root, int depth) {
    int d_left, d_right;
    d_left = d_right = 0;
    if (NULL != root->left) {
        d_left = get_depth_tree(root->left, (depth + 1));
    }
    if (NULL != root->right) {
        d_right = get_depth_tree(root->right, (depth + 1));
    }
    if (d_left > d_right) {
        return ++d_left;
    } else {
        return ++d_right;
    }
}

//* HUFFMAN_TREE END

//* CODE_TABLE START

char **alloc_code_table(int sizeChars) {
    char **table;
    table = (char **)malloc(sizeof(char *) * ASCII_SIZE);

    for (int i = 0; i < ASCII_SIZE; i++) {
        table[i] = calloc(sizeChars, sizeof(char));
        // table[i] = (char *) malloc(sizeof(char) * sizeChars);
    }

    return table;
}

void free_code_table(char **code_table) {
    for (int i = 0; i < ASCII_SIZE; i++) {
        free(code_table[i]);
    }
    free(code_table);
}

void generate_code_table(char **code_table, Node_tree *root_tree, char *path, int char_col) {
    char left[char_col], right[char_col];

    if ((NULL == root_tree->left) && (NULL == root_tree->right)) {
        strcpy(code_table[root_tree->let], path);
    } else {
        strcpy(left, path);
        strcat(left, "0");
        strcpy(right, path);
        strcat(right, "1");

        generate_code_table(code_table, root_tree->left, left, char_col);
        generate_code_table(code_table, root_tree->right, right, char_col);
    }
}

int calc_size_encoded_file(char **code_table, FILE *ptr_file) {
    int size = 0;
    for (char ch = fgetc(ptr_file); EOF != ch; ch = fgetc(ptr_file)) {
        size += strlen(code_table[ch]);
    }
    fseek(ptr_file, 0, SEEK_SET);
    return size;
}

char *encode(char **code_table, FILE *ptr_file) {
    int sizeEncode = calc_size_encoded_file(code_table, ptr_file);
    char *strEncode = calloc(sizeEncode, sizeof(char));

    for (char ch = fgetc(ptr_file); EOF != ch; ch = fgetc(ptr_file)) {
        strcat(strEncode, code_table[ch]);
    }
    fseek(ptr_file, 0, SEEK_SET);
    return strEncode;
}

char *decode(char *text, Node_tree *root) {
    Node_tree *aux;
    char temp[2];
    char *decode_text;

    decode_text = calloc(strlen(text), sizeof(char));
    aux = root;
    for (int i = 0; text[i] != '\0'; i++) {
        if ('0' == text[i]) {
            aux = aux->left;
        } else {
            aux = aux->right;
        }

        if ((NULL == aux->left) && (NULL == aux->right)) {
            // temp[0] = aux->left;
            // temp[1] = '\0';
            // strcat(decode_text, temp);
            strcat(decode_text, &aux->let);
            aux = root;
        }
    }
    strcat(decode_text, "\0");
    return decode_text;
}

//* CODE_TABLE END

//* ENCODE_FILE FUNCTIONS

void write_encode(char *str, char *file_path) {
    FILE *ptr_write;
    int j;
    char mask, byte;

    ptr_write = fopen(file_path, "wb");
    if (ptr_write) {
        j = 7;
        byte = 0;
        for (int i = 0; '\0' != str[i]; i++) {
            mask = 1;
            if ('1' == str[i]) {
                mask <<= j;
                byte |= mask;
            }
            j--;

            if (j < 0) {
                fwrite(&byte, sizeof(char), 1, ptr_write);
                byte = 0;
                j = 7;
            }
        }
        if (7 != j) {
            fwrite(&byte, sizeof(char), 1, ptr_write);
        }
        fclose(ptr_write);
    }
}

//* DECODE_FILE FUNCTIONS

unsigned int if_bit_one(char byte, int i) {
    char mask = (1 << i);
    return byte & mask;
}

void read_decode(Node_tree *root_tree, char *file_encoded, char *file_decode) {
    FILE *ptr_encoded, *ptr_decoded;
    Node_tree *aux;
    char byte;

    ptr_encoded = fopen(file_encoded, "rb");
    ptr_decoded = fopen(file_decode, "w");
    fclose(ptr_decoded);
    ptr_decoded = fopen(file_decode, "a");
    aux = root_tree;
    if (ptr_encoded) {
        while (fread(&byte, sizeof(char), 1, ptr_encoded)) {
            for (int i = 7; i >= 0; i--) {
                if (if_bit_one(byte, i)) {
                    aux = aux->right;
                } else {
                    aux = aux->left;
                }

                if ((NULL == aux->left) && (NULL == aux->right)) {
                    fwrite(&aux->let, sizeof(unsigned char), 1, ptr_decoded);
                    aux = root_tree;
                }
            }
        }
        fclose(ptr_decoded);
        fclose(ptr_encoded);
    }
}

//! DEBUG FUNCTIONS START

void set_PT_locale() {
    setlocale(LC_ALL, "Portuguese");
}

void test_OS_ASCII() {
    int cont = 0;
    printf("-------------------------------\n");
    printf("\tOS ASCII locale test - DEBUG START\n");
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (10 == cont) {
            printf("\n");
            cont = 0;
        }
        if (10 == i) {
            printf("\\n");
        } else {
            printf("%c", i);
        }
        cont++;
    }
    printf("\n");
    printf("\tOS ASCII locale test - DEBUG END\n");
    printf("-------------------------------\n");
}

void print_freq_table(unsigned int freq_table[ASCII_SIZE]) {
    printf("-------------------------------\n");
    printf("\tFrequency table - DEBUG START\n");
    for (int i = 0; i < ASCII_SIZE; i++) {
        //* when the char is \n (break line)
        if (0 < freq_table[i]) {
            if (10 == i) {
                printf("10\t\\n\t%i\n", freq_table[i]);
            } else {
                printf("%i\t%c\t%i\n", i, i, freq_table[i]);
            }
        }
    }
    printf("\tFrequency table - DEBUG END\n");
    printf("-------------------------------\n");
}

void print_huffman_tree(Node_tree *root) {
    if (NULL != root->left) {
        print_huffman_tree(root->left);
    }
    if (NULL != root->right) {
        print_huffman_tree(root->right);
    }
    printf("%c\n", root->let);
}

void print_code_table(char **code_table) {
    printf("\tCode_table\n");

    for (int i = 0; i < ASCII_SIZE; i++) {
        if (strlen(code_table[i]) > 0) {
            printf("\t%c\t%3d: %s\n", (char)i, i, code_table[i]);
        }
    }
}

//! DEBUG FUNCTIONS END

int main(int argc, char **argv) {
    //* var's declarations
    FILE *ptr_read;
    unsigned int freq_table[ASCII_SIZE] = {0};
    Huffman_tree *huffman;
    int charSize, encodeSize;
    char **code_table;
    char *strEncode;
    // char **path_encode;
    // char **path_decode;

    set_OS_locale();

    //* var's definitions
    // ptr_read = fopen(argv[1], "r"); //todo only to use vscode debug
    ptr_read = fopen("./files/debugSample", "r");

    //* freq_table actions
    fill_freq_table(ptr_read, freq_table);

    //* huffman_tree actions
    huffman = alloc_huffman();
    init_huffman_tree(huffman, freq_table);

    //* code_table actions
    charSize = get_depth_tree(huffman->root_tree, 0) - 1;
    code_table = alloc_code_table(charSize);
    generate_code_table(code_table, huffman->root_tree, "", charSize);

    //* codification actions

    // path_encode = (char **) malloc(sizeof(char *) * (strlen(argv[1]) + 6));
    // path_decode = (char **) malloc(sizeof(char *) * (strlen(argv[1]) + 6));

    strEncode = encode(code_table, ptr_read);



    write_encode(strEncode, "./writeSample");  // todo make this receive main args
    read_decode(huffman->root_tree, "./writeSample", "./decodeSample"); // todo make this receive main args

    //* free's

    // free(path_encode);
    // free(path_decode);
    free_code_table(code_table);
    free_huffman_tree(huffman->root_tree);

    return 0;
}