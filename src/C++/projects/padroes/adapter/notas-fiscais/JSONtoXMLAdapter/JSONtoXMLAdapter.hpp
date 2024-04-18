#ifndef JSONtoXMLAdapter_hpp
#define JSONtoXMLAdapter_hpp
#include "../XML/XML.hpp"
#include "../JSON/JSON.hpp"
#include "../Utils/SimulateFile/SimulateFile.hpp"

class JSONtoXMLAdapter:public XML {
    private:
        JSON *json;
    public:
        JSONtoXMLAdapter(JSON *json);
        ~JSONtoXMLAdapter();
        void getDadosFromFile(SimulateFile file);
        void getNome(char *output);
        void getCnpj(char *output);
        float getValorTotal();
};



#endif