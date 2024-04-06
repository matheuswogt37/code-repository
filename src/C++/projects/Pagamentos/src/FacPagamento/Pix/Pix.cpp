#include "Pix.hpp"

Pix::Pix():FacAbstractPagamento(){};

AbstractPagar* Pix::createPagar() {
    return new PixPagar();
}