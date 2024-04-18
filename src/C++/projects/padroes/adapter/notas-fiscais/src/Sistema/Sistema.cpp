#include "Sistema.hpp"

Sistema::Sistema(DataBase database) {
    this->dataBase = dataBase;
}
Sistema::~Sistema() {}

void Sistema::inserirNoBanco(XML *data) {
    this->dataBase.insert(data);
}