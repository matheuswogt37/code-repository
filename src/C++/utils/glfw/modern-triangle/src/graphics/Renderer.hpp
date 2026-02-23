#pragma once
#include "../objects/Triangle.hpp"
#include "Shader.hpp"

class Renderer {
    private:
        unsigned int vao, vbo;
    public:
        Shader shader;
        Renderer();
        ~Renderer();
        void draw(const Triangle &triangle);
};