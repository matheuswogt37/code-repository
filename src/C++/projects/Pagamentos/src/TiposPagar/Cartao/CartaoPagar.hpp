#ifndef CartaoPagar_hpp
#define CartaoPagar_hpp
#include "../../AbstractPagar/AbstractPagar.hpp"

class CartaoPagar:public AbstractPagar {
    public:
        CartaoPagar() : AbstractPagar() {};
        ~CartaoPagar();
        void pagar();
};


#endif