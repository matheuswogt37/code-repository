#ifndef AbstractPagar_hpp
#define AbstractPagar_hpp
#include <stdio.h>

class AbstractPagar {
    protected:
        AbstractPagar();
    public:
        ~AbstractPagar();
        virtual void pagar();
};


#endif