#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

/// @brief Representa onde, orientacao e escala da entidade
struct Transform
{
    /// @brief posicao no espaco de mundo
    glm::vec3 position {0.f};
    /// @brief Quaternion representa rotacao como eixo + angulo de forma continua e estavel
    glm::quat rotation {1.f, 0.f, 0.f, 0.f};
    /// @brief escala 3D da entidade
    glm::vec3 scale {1.f};

    /// @brief matriz que transforma do espaco local para o espaco de mundo
    glm::mat4 modelMatrix {1.f};
    /// @brief indica se o modelMatrix precisa ser recalculado
    bool dirty = true;

    void updateMatrix() {
        modelMatrix = glm::translate(glm::mat4(1.f), position) * glm::toMat4(rotation) * glm::scale(glm::mat4(1.f), scale);
        dirty = false;
    }
};