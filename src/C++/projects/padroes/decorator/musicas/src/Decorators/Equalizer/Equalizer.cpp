#include "Equalizer.hpp"

Equalizer::Equalizer(Music *w) : BaseDecorator(w) {}
Equalizer::~Equalizer() {}

void Equalizer::play(std::string music) {
    std::cout << "Equalizer applyed" << std::endl;
    BaseDecorator::play(music);
}