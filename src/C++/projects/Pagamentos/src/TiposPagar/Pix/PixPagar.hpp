#ifndef PixPagar_hpp
#define PixPagar_hpp
#include "../../AbstractPagar/AbstractPagar.hpp"

class PixPagar:public AbstractPagar {
    public:
        PixPagar();
        ~PixPagar();
        void pagar();
};


#endif