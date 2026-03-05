#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoord;
};

/// @brief  Um conjunto de vértices + índices que definem uma forma.
class Mesh {
    private:
        VertexArray vao;
        VertexBuffer* vbo;
        IndexBuffer* ebo;
        unsigned int indexCount;
    public:
        Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices);
        ~Mesh();
        void draw() const;
};