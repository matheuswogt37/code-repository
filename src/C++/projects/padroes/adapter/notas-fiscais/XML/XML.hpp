#ifndef XML_hpp
#define XML_hpp
#include "../Utils/SimulateFile/SimulateFile.hpp"

class XML {
    public:
        virtual void getDadosFromFile(SimulateFile file) = 0;
        virtual void getNome(char *output) = 0;
        virtual void getCnpj(char *output) = 0;
        virtual float getValorTotal() = 0;
};

#endif