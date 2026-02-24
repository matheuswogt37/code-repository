#include "Mesh.hpp"

Mesh::Mesh(const std::vector<float>& vertices)
{
    indexed = false;
    vertexCount = vertices.size() / 3;

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER,
                 vertices.size() * sizeof(float),
                 vertices.data(),
                 GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
                          3 * sizeof(float),
                          (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

Mesh::Mesh(const std::vector<float>& vertices,
           const std::vector<unsigned int>& indices)
{
    indexed = true;
    indexCount = indices.size();

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    // VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER,
                 vertices.size() * sizeof(float),
                 vertices.data(),
                 GL_STATIC_DRAW);

    // EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 indices.size() * sizeof(unsigned int),
                 indices.data(),
                 GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
                          3 * sizeof(float),
                          (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);

    if (indexed)
        glDeleteBuffers(1, &ebo);
}

void Mesh::draw() const
{
    glBindVertexArray(vao);

    if (indexed)
    {
        glDrawElements(GL_TRIANGLES,
                       indexCount,
                       GL_UNSIGNED_INT,
                       0);
    }
    else
    {
        glDrawArrays(GL_TRIANGLES,
                     0,
                     vertexCount);
    }

    glBindVertexArray(0);
}