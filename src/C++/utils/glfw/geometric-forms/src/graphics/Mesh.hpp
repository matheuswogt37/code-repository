#pragma once
#include <vector>
#include "../../external/glad/include/glad/glad.h"

class Mesh {
    private:
        unsigned int vao = 0;
        unsigned int vbo = 0;           //* vbo (Vertex Buffer Objects)
        unsigned int ebo = 0;
        unsigned int vertexCount = 0;
        unsigned int indexCount = 0;
        bool indexed = false;
    public:
        Mesh(const std::vector<float> &vertices);
        Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);
        ~Mesh();
        void draw() const;
};