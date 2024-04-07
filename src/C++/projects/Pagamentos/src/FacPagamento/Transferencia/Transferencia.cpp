#include "Transferencia.hpp"

Transferencia::Transferencia(){};
Transferencia::~Transferencia(){};

AbstractPagar* Transferencia::createPagar() {
    AbstractPagar* Transferencia = new TransferenciaPagar();
    return Transferencia;
}