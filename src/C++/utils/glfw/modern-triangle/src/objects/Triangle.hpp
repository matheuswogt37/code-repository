#pragma once
#include "../math/Transform.hpp"

class Triangle {
    public:
        Transform transform;
        float moveSpeed = 1.5f;
        float rotateSpeed = 50.f;
        float r = 0.2f;
        float g = 0.7f;
        float b = 0.0f;
        float a = 1.0f;
        Triangle();
        ~Triangle();
        void update(float dateTime, bool moveLeft, bool moveRight, bool moveUp, bool moveDown, bool rotateLeft, bool rotateRight);
};