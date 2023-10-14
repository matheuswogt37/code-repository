#include <stdio.h>
#include "queue.c"

int main() {
    Queue *queue;
    queue = allocQueue();

    errorTreatment(insertNode(queue, 1));
    errorTreatment(insertNode(queue, 2));
    errorTreatment(insertNode(queue, 3));
    errorTreatment(insertNode(queue, 4));
    errorTreatment(insertNode(queue, 5));

    errorTreatment(printQueue(queue));

    errorTreatment(removeNode(queue));
    
    errorTreatment(printQueue(queue));

    clearQueue(queue);

    errorTreatment(printQueue(queue));

    freeQueue(queue);
    return 1;
}