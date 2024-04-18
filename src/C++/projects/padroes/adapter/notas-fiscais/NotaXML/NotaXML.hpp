#ifndef NotaXML_hpp
#define NotaXML_hpp
#include "../XML/XML.hpp"
#include "../Utils/SimulateFile/SimulateFile.hpp"

class NotaXML:public XML {
    private:
        char nome[30];
        char cnpj[20];
        float valorTotal;
    public:
        NotaXML();
        ~NotaXML();
        void getDadosFromFile(SimulateFile file);
        void getNome(char *output);
        void getCnpj(char *output);
        float getValorTotal();
};

#endif