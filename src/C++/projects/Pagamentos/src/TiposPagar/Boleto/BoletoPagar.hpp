#ifndef BoletoPagar_hpp
#define BoletoPagar_hpp
#include "../../AbstractPagar/AbstractPagar.hpp"

class BoletoPagar:public AbstractPagar {
    public:
        BoletoPagar();
        ~BoletoPagar();
        void pagar();
};


#endif