#include "Shader.hpp"

unsigned int Shader::compileShader(unsigned int type, const std::string &source) {
    unsigned int id = glCreateShader(type); //* like 'GL_VERTEX_SHADER' or 'GL_FRAGMENT_SHADER'
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr); //* sets the source code in shader to the source code in the array of strings specified by string <registry.khronos.org>
    glCompileShader(id); //* compiles the source code strings that have been stored in the shader object specified by shader <registry.khronos.org>

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) { //* error when compile shader
        int length;

        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char *message = new char[length];
        glGetShaderInfoLog(id, length, &length, message);

        std::cout << "Shader compilation failed: " << message << "\n";
        delete[] message;

        glDeleteShader(id);
        return 0;
    }

    return id;
}

Shader::Shader(const std::string &vertexPath, const std::string &fragmentPath) {
    unsigned int vertex = compileShader(GL_VERTEX_SHADER, vertexPath);
    if (vertex == 0) {
        return;
    }

    unsigned int fragment = compileShader(GL_FRAGMENT_SHADER, fragmentPath);
    if (fragment == 0) {
        return;
    }

    this->programID = glCreateProgram();
    glAttachShader(this->programID, vertex);
    glAttachShader(this->programID, fragment);
    glLinkProgram(this->programID);
    glValidateProgram(this->programID);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::~Shader() {
    glDeleteProgram(this->programID);
}

void Shader::bind() const {
    glUseProgram(this->programID);
}

void Shader::unbind() const {
    glUseProgram(0);
}

void Shader::setMat4(const std::string &name, const glm::mat4 &value) {
    glUniformMatrix4fv(glGetUniformLocation(this->programID, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

void Shader::setVec3(const std::string &name, const glm::vec3 &value) {
    glUniform3f(glGetUniformLocation(this->programID, name.c_str()), value.x, value.y, value.z);
}

void Shader::setFloat(const std::string &name, float value) {
    glUniform1f(glGetUniformLocation(this->programID, name.c_str()), value);
}