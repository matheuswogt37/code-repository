#ifndef TransferenciaPagar_hpp
#define TransferenciaPagar_hpp
#include "../../AbstractPagar/AbstractPagar.hpp"

class TransferenciaPagar:public AbstractPagar {
    public:
        TransferenciaPagar();
        ~TransferenciaPagar();
        void pagar();
};


#endif