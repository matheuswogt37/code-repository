#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../Component.hpp"
struct CameraComponent : public Component{
    float fov = 45.f;
    float aspect = 1.77f;
    float nearPlane = 0.1f;
    float farPlane = 100.f;

    glm::mat4 projection {1.f};

    bool primary = true;

    bool dirty = true;

    void updateProjection() {
        projection = glm::perspective(glm::radians(fov), aspect, nearPlane, farPlane);
        dirty = false;
    }
};