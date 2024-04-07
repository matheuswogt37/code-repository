#include "FacPagamento/Pix/Pix.hpp"
#include "FacPagamento/Cartao/Cartao.hpp"
#include "FacPagamento/Boleto/Boleto.hpp"
#include "FacPagamento/Transferencia/Transferencia.hpp"
#include <iostream>
using namespace std;


int main() {

    Transferencia pixTemp;
    AbstractPagar* pix = pixTemp.createPagar();
    pix->pagar();

    return 0;
}