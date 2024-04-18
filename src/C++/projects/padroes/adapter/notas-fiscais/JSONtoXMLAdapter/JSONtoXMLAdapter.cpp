#include "JSONtoXMLAdapter.hpp"

JSONtoXMLAdapter::JSONtoXMLAdapter(JSON *json)
{
    this->json = json;
};
JSONtoXMLAdapter::~JSONtoXMLAdapter(){};

void JSONtoXMLAdapter::getDadosFromFile(SimulateFile file)
{
    this->json->getDadosFromFile(file);
}

void JSONtoXMLAdapter::getNome(char *output) {
    this->json->getNome(output);
}

void JSONtoXMLAdapter::getCnpj(char *output) {
    this->json->getCnpj(output);
}

float JSONtoXMLAdapter::getValorTotal() {
    return this->json->getValorTotal();
}