#include "Pix.hpp"

Pix::Pix(){};
Pix::~Pix(){};

AbstractPagar* Pix::createPagar() {
    AbstractPagar* pix = new PixPagar();
    return pix;
}