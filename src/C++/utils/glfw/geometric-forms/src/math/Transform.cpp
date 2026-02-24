#include "Transform.hpp"

glm::mat4 Transform::getMatrix() const {
    glm::mat4 model = glm::mat4(1.f);

    model = glm::translate(model, glm::vec3(position, 0.f));
    model = glm::rotate(model, glm::radians(rotation), glm::vec3(0,0,1));
    model = glm::scale(model, glm::vec3(scale, 1.f));

    return model;
}