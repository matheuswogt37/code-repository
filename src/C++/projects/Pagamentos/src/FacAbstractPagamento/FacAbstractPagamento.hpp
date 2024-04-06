#ifndef FacAbstractPagamento_hpp
#define FacAbstractPagamento_hpp
#include "../AbstractPagar/AbstractPagar.hpp"

class FacAbstractPagamento {
    protected:
        FacAbstractPagamento();
    public:
        ~FacAbstractPagamento();
        virtual AbstractPagar* createPagar();
};

#endif