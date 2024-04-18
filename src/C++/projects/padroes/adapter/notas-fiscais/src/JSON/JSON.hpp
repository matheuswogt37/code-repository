#ifndef JSON_hpp
#define JSON_hpp
#include "../Utils/SimulateFile/SimulateFile.hpp"

class JSON {
    public:
        virtual void getDadosFromFile(SimulateFile file){};
        virtual void getNome(char *output) = 0;
        virtual void getCnpj(char *output) = 0;
        virtual float getValorTotal() = 0;
};

#endif