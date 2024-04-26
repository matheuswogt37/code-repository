#include "BaseDecorator.hpp"

BaseDecorator::BaseDecorator(Music *w) : Music()
{
    this->wrapper = w;
}
BaseDecorator::~BaseDecorator() {}

void BaseDecorator::play(std::string music) {
    this->wrapper->play(music);
}