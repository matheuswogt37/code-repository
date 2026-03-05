#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct CameraComponent {
    float fov = 45.f;
    float aspect = 1.77f;
    float nearPlane = 0.1f;
    float farPlane = 100.f;

    glm::mat4 projection {1.f};

    bool primary = true;

    void updateProjection() {
        projection = glm::perspective(glm::radians(fov), aspect, nearPlane, farPlane);
    }
};