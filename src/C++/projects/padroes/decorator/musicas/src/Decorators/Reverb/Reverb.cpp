#include "Reverb.hpp"

Reverb::Reverb(Music *w) : BaseDecorator(w) {}
Reverb::~Reverb() {}

void Reverb::play(std::string music) {
    std::cout << "Reverb applyed" << std::endl;
    BaseDecorator::play(music);
}