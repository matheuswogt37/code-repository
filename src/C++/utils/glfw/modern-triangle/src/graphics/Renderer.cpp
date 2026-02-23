#include "Renderer.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Vertex shader
const char* vertexShaderSrc = R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;
    uniform mat4 transform;
    void main()
    {
        gl_Position = transform * vec4(aPos, 1.0);
    }
)";

// Fragment shader
const char* fragmentShaderSrc = R"(
    #version 330 core
    out vec4 FragColor;
    void main()
    {
        FragColor = vec4(0.2, 0.7, 1.0, 1.0);
    }
)";

Renderer::Renderer() : shader(vertexShaderSrc, fragmentShaderSrc) {
    // Triangle vertices
    float vertices[] = {
        -0.6f, -0.4f, 0.0f,
         0.6f, -0.4f, 0.0f,
         0.0f,  0.6f, 0.0f
    };

    glGenVertexArrays(1, &this->vao);
    glGenBuffers(1, &this->vbo);

    glBindVertexArray(this->vao);

    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

Renderer::~Renderer() {
    glDeleteVertexArrays(1, &this->vao);
    glDeleteBuffers(1, &this->vbo);
}

void Renderer::draw(const Triangle &triangle) {
    this->shader.use();

    glm::mat4 transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(triangle.transform.x, triangle.transform.y, 0.0f));
    transform = glm::rotate(transform, glm::radians(triangle.transform.rotation), glm::vec3(0.0f, 0.0f, 1.0f));

    this->shader.setMat4("transform", glm::value_ptr(transform));

    glBindVertexArray(this->vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}