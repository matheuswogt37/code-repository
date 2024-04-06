#include "FacPagamento/Pix/Pix.hpp"
#include <iostream>
using namespace std;


int main() {

    Pix pixTemp;
    AbstractPagar* pix = pixTemp.createPagar();
    pix->pagar();

    return 0;
}