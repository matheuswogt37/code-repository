#pragma once
#include "../Registry.hpp"
class MovementSystem {
    public:
        MovementSystem();
        void update(Registry registry, float dt);
};