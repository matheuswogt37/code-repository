#include "Shader.hpp"

void Shader::checkCompileErrors(unsigned int object, const std::string& type) {
    int success;
    char infoLog[1024];

    if (type != "PROGRAM")
    {
        glGetShaderiv(object, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(object, 1024, nullptr, infoLog);
            std::cout << "Shader compile error:\n" << infoLog << std::endl;
        }
    }
    else
    {
        glGetProgramiv(object, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(object, 1024, nullptr, infoLog);
            std::cout << "Program link error:\n" << infoLog << std::endl;
        }
    }
}

Shader::Shader(const char* vertexSrc, const char* fragmentSrc) {
    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexSrc, NULL);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");

    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentSrc, NULL);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");

    this->id = glCreateProgram();
    glAttachShader(this->id, vertex);
    glAttachShader(this->id, fragment);
    glLinkProgram(this->id);
    checkCompileErrors(this->id, "PROGRAM");

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
    glUniform4f(glGetUniformLocation(this->id, name.c_str()), x, y, z, w);
}