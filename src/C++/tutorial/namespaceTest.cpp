#include <iostream>
using namespace std;
// this line is used for get functions from 'std' and use as normal functions

namespace A
{
    int x = 10;
    void printX() {
        cout << "x = " << x << endl;
    }
}

using namespace A;
// with this line, the function 'printX' can be used without 'A::'

namespace B {
    int y = 7;
    void printY() {
        cout << "y = " << y << endl;
    }
}
// because not write 'using namespace B' the function printY needs 'B::' before call the function


int main()
{
    // from namespace A
    printX();

    // from namespace B
    B::printY();
    return 0;
}