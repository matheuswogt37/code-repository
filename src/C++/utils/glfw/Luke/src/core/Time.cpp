#include "Time.hpp"

void Time::update() {
    this->deltaTime = glfwGetTime() - this->lastTime;
}

Time::Time() {
    this->lastTime = 0.f;
    update();
}

Time::~Time() {}

float Time::getDeltaTime() {
    return this->deltaTime;
}