#ifndef Pix_hpp
#define Pix_hpp
#include "../../FacAbstractPagamento/FacAbstractPagamento.hpp"
#include "../../TiposPagar/Pix/PixPagar.hpp"

class Pix:public FacAbstractPagamento {
    public:
        Pix();
        ~Pix();
        AbstractPagar* createPagar();
};

#endif