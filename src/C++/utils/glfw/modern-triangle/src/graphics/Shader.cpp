#include "Shader.hpp"

Shader::Shader(const char* vertexSrc, const char* fragmentSrc) {
    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexSrc, NULL);
    glCompileShader(vertex);

    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentSrc, NULL);
    glCompileShader(fragment);

    this->id = glCreateProgram();
    glAttachShader(this->id, vertex);
    glAttachShader(this->id, fragment);
    glLinkProgram(this->id);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::~Shader() {
    glDeleteProgram(this->id);
}

void Shader::use() const {
    glUseProgram(this->id);
}

void Shader::setMat4(const std::string &name, const float *matrix) const {
    glUniformMatrix4fv(glGetUniformLocation(this->id, name.c_str()), 1, GL_FALSE, matrix);
}

void Shader::setVec4(const std::string& name, float x, float y, float z, float w) const {
    glUniform4f(
        glGetUniformLocation(this->id, name.c_str()),
        x, y, z, w
    );
}