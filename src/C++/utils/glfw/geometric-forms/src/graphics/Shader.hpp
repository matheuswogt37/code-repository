#pragma once
#include <string>
#include <iostream>
#include "../../external/glad/include/glad/glad.h"

class Shader {
    private:
        void checkCompileErrors(unsigned int shader, const std::string& type);
    public:
        unsigned int id;
        Shader(const char* vertexSrc, const char* fragmentSrc);
        ~Shader();
        void use() const;
        void setMat4(const std::string &name, const float *matrix) const;
        void setVec4(const std::string& name, float x, float y, float z, float w) const;
};