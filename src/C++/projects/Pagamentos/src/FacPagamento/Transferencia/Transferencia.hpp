#ifndef Transferencia_hpp
#define Transferencia_hpp
#include "../../FacAbstractPagamento/FacAbstractPagamento.hpp"
#include "../../TiposPagar/Transferencia/TransferenciaPagar.hpp"

class Transferencia:public FacAbstractPagamento {
    public:
        Transferencia();
        ~Transferencia();
        AbstractPagar* createPagar();
};

#endif