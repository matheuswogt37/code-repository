#pragma once
#include <string>
#include "../../external/glad/include/glad/glad.h"

class Shader {
    public:
        unsigned int id;
        Shader(const char* vertexSrc, const char* fragmentSrc);
        ~Shader();
        void use() const;
        void setMat4(const std::string &name, const float *matrix) const;
};