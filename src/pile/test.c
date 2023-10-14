#include <stdio.h>
#include "pile.c"

int main() {

    Pile *queue;
    queue = allocPile();

    errorTreatment(insertNode(queue, 1));
    errorTreatment(insertNode(queue, 2));
    errorTreatment(insertNode(queue, 3));
    errorTreatment(insertNode(queue, 4));
    errorTreatment(insertNode(queue, 5));

    errorTreatment(printPile(queue));

    errorTreatment(removeNode(queue));
    errorTreatment(removeNode(queue));

    errorTreatment(printPile(queue));

    clearPile(queue);

    errorTreatment(printPile(queue));

    freePile(queue);
    return 0;
}