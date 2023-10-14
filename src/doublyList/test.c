#include <stdio.h>
#include "doublyLinkedList.c"
#define arrayLength(array) (int) (sizeof((array)) / sizeof((array)[0]))


int main() {

    int addEle[] = {1, 3, 5, 7, 1, 2};
    List *queue;
    queue = allocList();
    int arrayLenght = arrayLength(addEle);

    for (int i = 0; i < arrayLenght; i++) {
        insertNodo(queue, queue->tail, addEle[i]);
    }

    printList(queue);
    
    removeNode(queue, queue->head);

    printList(queue);

    clearDoublyList(queue);

    printList(queue);



    return 0;
}