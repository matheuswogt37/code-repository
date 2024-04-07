#include "Cartao.hpp"

Cartao::Cartao(){};
Cartao::~Cartao(){};

AbstractPagar* Cartao::createPagar() {
    AbstractPagar* Cartao = new CartaoPagar();
    return Cartao;
}