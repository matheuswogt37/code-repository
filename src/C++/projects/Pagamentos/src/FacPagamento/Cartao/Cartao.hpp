#ifndef Cartao_hpp
#define Cartao_hpp
#include "../../FacAbstractPagamento/FacAbstractPagamento.hpp"
#include "../../TiposPagar/Cartao/CartaoPagar.hpp"

class Cartao:public FacAbstractPagamento {
    public:
        Cartao();
        ~Cartao();
        AbstractPagar* createPagar();
};

#endif