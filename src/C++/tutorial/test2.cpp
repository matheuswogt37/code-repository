#include <iostream>
using namespace std;





int main() {

    int* ptrArray = (int*) malloc(sizeof(int) * 10);
    ptrArray[0] = 1;
    ptrArray[1] = 2;
    ptrArray[2] = 3;

    cout << ptrArray[1]+"\n"+sizeof(ptrArray);

    free(ptrArray);
    return 0;
}