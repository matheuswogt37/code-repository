#ifndef AbstractPagar_hpp
#define AbstractPagar_hpp
#include <iostream>

class AbstractPagar {
    protected:
        AbstractPagar();
    public:
        ~AbstractPagar();
        virtual void pagar(){};
};


#endif