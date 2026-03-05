#pragma once
#include <string>
#include <iostream>
#include <glm/common.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../../external/glad/include/glad/glad.h"

/// @brief programa que roda na GPU para transformar geometria em pixels.
class Shader {
    private:
        /// @brief shader ID
        unsigned int programID;
        /// @brief compilador generico para shader
        unsigned int compileShader(unsigned int type, const std::string &source);
    public:
        /// @brief
        /// @param vertexPath - e o primeiro estagio e processa cada vrtice individualmente. Seu objetivo principal e transformar coordenadas 3D em outras coordenadas 3D e realizar processamentos basicos nos atributos dos vertices
        /// @param fragmentPath - Sua funcao principal e calcular a cor final de um pixel. E nesta fase que ocorrem os efeitos mais avançados, como calculos de iluminacao, sombras e cores complexas
        Shader(const std::string &vertexPath, const std::string &fragmentPath);

        void bind() const;
        void unbind() const;

        void setMat4(const std::string &name, const glm::mat4 &value);
        void setVec3(const std::string &name, const glm::vec3 &value);
        void setFloat(const std::string &name, float value);
};