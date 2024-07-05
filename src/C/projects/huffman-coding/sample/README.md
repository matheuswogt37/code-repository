# Huffman encrypt

## About

## How compile

### Requirements

## How to use

## Examples

## TO-DO project

### General

- [ ] Make macro to exit program
- [ ] When all tested and work, copy all the code too a final version (remove all debug content)
- [ ] Confirm locale settings

### Read file - ptr_read

The file name will be passed by parameter to main function, if exist then continue, if not then print error and return FAILURE

- [ ] Code verification if the file was valid, if not call macro exit_program
- [ ] Verify when not used anymore and close the file - fclose

### Frequency table - freq_table

The frequency table will use ascii codes to identify letter frequencies, when encrypting big texts this will be more efficient than use a list. Actualy the ASCII table to use is:

![ASCII table reference](/src/C/projects/huffman-coding/sample/imgs/ASCII_table.jpg)

- [X] Do frequency table using **unsigned int array[ascii size]**
- [X] Code functions (fill_freq_table)
- [X] Code frequency table debug functions (print)
- [ ] Set portuguesse location - to use ascii 256, until use 128 NOT WORKING I DO'T KNOW
- [ ] Tests

### Node_tree

Node had a 'unsigned char let' that represent the letter in this node, 'int freq' the frequency from freq_table, '*left' and '*right'  meas the "children" of that node, this is attributes that only are used in a tree

- [X] Create struct to node
- [X] Code alloc and free
- [ ] Certify they is being used

### Node_list

This node_list contain two things:
-   Node_tree
-   *next

- [X] Create struct
- [X] code alloc

### Huffman_tree

This structure contains two attributes:
1.  Node_list
2.  Node_tree

- [X] Create struct to tree
- [X] Code alloc and free (free will free node_list and node_huffman)
- [ ] Certify they is being used
- [X] Code list functions (insert_huffman_list, remove_huffman_list, init_huffman_list)
- [ ] Code tree functions (insert_huffman_tree, init_huffman_tree, get_depth_tree)
- [X] Tests

### Code_table

This is the dictionary thar are used to compact and decompact the files

- [ ] Create the char pointer pointer ( char** )
- [ ] Code alloc and free
- [ ] Certify they is being used
- [ ] Code code_table functions (init_code_table, compact_char, decompact_char)
- [ ] Tests