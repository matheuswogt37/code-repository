#include "Triangle.hpp"

Triangle::Triangle() {};
Triangle::~Triangle() {};

void Triangle::update(float deltaTime, bool moveLeft, bool moveRight, bool moveUp, bool moveDown, bool rotateLeft, bool rotateRight) {
    if (moveLeft) {
        this->transform.x -= this->moveSpeed * deltaTime;
    }
    if (moveRight) {
        this->transform.x += this->moveSpeed * deltaTime;
    }
    if (moveDown) {
        this->transform.y -= this->moveSpeed * deltaTime;
    }
    if (moveUp) {
        this->transform.y += this->moveSpeed * deltaTime;
    }

    if (rotateLeft) {
        this->transform.rotation += this->rotateSpeed * deltaTime;
    }
    if (rotateRight) {
        this->transform.rotation -= this->rotateSpeed * deltaTime;
    }
}