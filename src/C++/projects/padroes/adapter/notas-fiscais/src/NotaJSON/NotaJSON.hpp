#ifndef NotaJSON_hpp
#define NotaJSON_hpp
#include "../JSON/JSON.hpp"
#include "../Utils/SimulateFile/SimulateFile.hpp"

#include <iostream>

class NotaJSON:public JSON {
    private:
        char nome[30];
        char cnpj[30];
        float valorTotal;
    public:
        NotaJSON();
        ~NotaJSON();
        void getDadosFromFile(SimulateFile file);
        void getNome(char *output);
        void getCnpj(char *output);
        float getValorTotal();
};

#endif