#include "Eco.hpp"

Eco::Eco(Music *w) : BaseDecorator(w) {}
Eco::~Eco() {}

void Eco::play(std::string music) {
    std::cout << "Eco applyed" << std::endl;
    BaseDecorator::play(music);
}