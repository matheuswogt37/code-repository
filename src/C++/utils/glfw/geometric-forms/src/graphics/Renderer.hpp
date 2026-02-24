#pragma once
#include <glm/gtc/type_ptr.hpp>
#include "../gameObject/GameObject.hpp"
#include "Shader.hpp"

class Renderer {
    public:
        Shader shader;
        Renderer();
        ~Renderer();
        void draw(const GameObject &obj);
};