#include "NotaXML.hpp"

NotaXML::NotaXML() {};
NotaXML::~NotaXML() {};
void NotaXML::getDadosFromFile(SimulateFile file) {
    for (int i = 0; i < 30; i++) {
        this->nome[i] = file.nome[i];
    }
    for (int i = 0; i < 30; i++) {
        this->cnpj[i] = file.cnpj[i];
    }
    this->valorTotal = file.valorTotal;
}

void NotaXML::getNome(char *output) {
    for (int i = 0; i < 30; i++) {
        output[i] = this->nome[i];
    }
}

void NotaXML::getCnpj(char *output) {
    for (int i = 0; i < 30; i++) {
        output[i] = this->cnpj[i];
    }
}

float NotaXML::getValorTotal() {
    return this->valorTotal;
}