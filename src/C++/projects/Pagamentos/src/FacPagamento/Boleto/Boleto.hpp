#ifndef Boleto_hpp
#define Boleto_hpp
#include "../../FacAbstractPagamento/FacAbstractPagamento.hpp"
#include "../../TiposPagar/Boleto/BoletoPagar.hpp"

class Boleto:public FacAbstractPagamento {
    public:
        Boleto();
        ~Boleto();
        AbstractPagar* createPagar();
};

#endif