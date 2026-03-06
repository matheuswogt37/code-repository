#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../Component.hpp"
struct Transform : public Component {
    glm::vec3 position {0.f};
    glm::quat rotation {1.f, 0.f, 0.f, 0.f};
    glm::vec3 scale {1.f};

    private:
        glm::mat4 modelMatrix {1.f};
        bool dirty = true;
        void updateMatrix() {
            glm::mat4 translation = glm::translate(glm::mat4(1.f), position);
            glm::mat4 rotationMat = glm::mat4_cast(rotation);
            glm::mat4 scaleMat = glm::scale(glm::mat4(1.f), scale);

            modelMatrix = translation * rotationMat * scaleMat;

            dirty = false;
        }
    public:
        const glm::mat4 getModelMatrix() {
            if (dirty) {
                updateMatrix();
            }
            return modelMatrix;
        }

        void setPosition(const glm::vec3 &pos) {
            position = pos;
            dirty = true;
        }

        void setRotation(const glm::quat &rot) {
            rotation = rot;
            dirty = true;
        }

        void setScale(const glm::vec3 &s) {
            scale = s;
            dirty = true;
        }
};