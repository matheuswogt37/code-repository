#pragma once
#include "../math/Transform.hpp"

class Triangle {
    public:
        Transform transform;
        float moveSpeed = 1.5f;
        float rotateSpeed = 50.f;
        Triangle();
        ~Triangle();
        void update(float dateTime, bool moveLeft, bool moveRight, bool moveUp, bool moveDown, bool rotateLeft, bool rotateRight);
};