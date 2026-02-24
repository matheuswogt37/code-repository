#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform {
    public:
        glm::vec2 position {0.f, 0.f};
        float rotation = 0.f;
        glm::vec2 scale {1.f, 1.f};

        glm::mat4 getMatrix() const;
};