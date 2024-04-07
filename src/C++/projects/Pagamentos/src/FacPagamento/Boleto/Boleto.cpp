#include "Boleto.hpp"

Boleto::Boleto(){};
Boleto::~Boleto(){};

AbstractPagar* Boleto::createPagar() {
    AbstractPagar* Boleto = new BoletoPagar();
    return Boleto;
}