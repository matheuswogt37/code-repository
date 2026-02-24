#include "Renderer.hpp"

static const char* vertexSrc = R"(
#version 330 core
layout (location = 0) in vec3 aPos;
uniform mat4 transform;
void main()
{
    gl_Position = transform * vec4(aPos, 1.0);
}
)";

static const char* fragmentSrc = R"(
#version 330 core
out vec4 FragColor;
uniform vec4 uColor;
void main()
{
    FragColor = uColor;
}
)";

Renderer::Renderer() : shader(vertexSrc, fragmentSrc) {};
Renderer::~Renderer() {};

void Renderer::draw(const GameObject& obj)
{
    shader.use();
    shader.setMat4("transform",
                   glm::value_ptr(obj.transform.getMatrix()));

    shader.setVec4("uColor",
                   obj.material.color.r,
                   obj.material.color.g,
                   obj.material.color.b,
                   obj.material.color.a);

    obj.mesh->draw();
}