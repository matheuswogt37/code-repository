#include "DataBase.hpp"

DataBase::DataBase() {};
DataBase::~DataBase() {};

void DataBase::insert(XML *data) {
    char nome[30];
    char cnpj[30];
    float valorTotal;

    data->getNome(nome);
    data->getCnpj(cnpj);
    valorTotal = data->getValorTotal();

    std::cout << "Dados cadastrados:\n";
    std::cout << "Nome - " << nome << "\n";
    std::cout << "CNPJ - " << cnpj << "\n";
    std::cout << "Valor Total - R$" << valorTotal << "\n";
}