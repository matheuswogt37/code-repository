#include <stdio.h>
#define arrayLength(array) (int) (sizeof((array)) / sizeof((array)[0]))
#include "linkedList.c"

int main() {

    List *queue;
    queue = allocList();

   int vals[] = {1, 3, 5, 2, 9, 0, 3, 5, 2};
   
   printf("size = %i\n", arrayLength(vals));

   insertNode(queue, queue->head, 4);

    for (int i = 0; i < (arrayLength(vals)); i++) {
        insertNode(queue, queue->tail, vals[i]);
    }
    printList(queue);

    removeNode(queue, queue->head);

    printList(queue);

    freeList(queue);
    return 1;
}