#include "NotaJSON.hpp"

NotaJSON::NotaJSON() {};
NotaJSON::~NotaJSON() {};

void NotaJSON::getDadosFromFile(SimulateFile file) {
    for (int i = 0; i < 30; i++) {
        this->nome[i] = file.nome[i];
    }
    for (int i = 0; i < 30; i++) {
        this->cnpj[i] = file.cnpj[i];
    }
    this->valorTotal = file.valorTotal;
}

void NotaJSON::getNome(char *output) {
    for (int i = 0; i < 30; i++) {
        output[i] = this->nome[i];
    }
}

void NotaJSON::getCnpj(char *output) {
    for (int i = 0; i < 30; i++) {
        output[i] = this->cnpj[i];
    }
}

float NotaJSON::getValorTotal() {
    return this->valorTotal;
}