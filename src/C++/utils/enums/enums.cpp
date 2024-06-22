#include <iostream>
#include "enums.hpp"

void mostrarEscolha(ESTADOS escolha) {
    switch(escolha) {
        case ACRE:
            std::cout << "vc escolheu o ACRE! - cod " << escolha << std::endl;
            break;
        case MARANHAO:
            std::cout << "vc escolheu o MARANHAO! - cod " << escolha << std::endl;
            break;
        case RIOJANEIRO:
            std::cout << "vc escolheu o RIOJANEIRO! - cod " << escolha << std::endl;
            break;
        case SANTACATARINA:
            std::cout << "vc escolheu o SANTACATARINA! - cod " << escolha << std::endl;
            break;
        case SERGIPE:
            std::cout << "vc escolheu o SERGIPE! - cod " << escolha << std::endl;
            break;
        default:
            std::cout << "vc escolheu algum outro!" << std::endl;
            break;
    }
}

int main() {
    ESTADOS escolha;
    escolha = ACRE;
    mostrarEscolha(escolha);
    escolha = AMAPA;
    mostrarEscolha(escolha);
    escolha = RIOJANEIRO;
    mostrarEscolha(escolha);
    escolha = SANTACATARINA;
    mostrarEscolha(escolha);
    escolha = PIAUI;
    mostrarEscolha(escolha);
    escolha = SERGIPE;
    mostrarEscolha(escolha);
    escolha = TORIXOREU;
    mostrarEscolha(escolha);
}