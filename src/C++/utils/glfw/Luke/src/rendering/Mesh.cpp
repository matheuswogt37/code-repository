#include "Mesh.hpp"

Mesh::Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices) {
    this->indexCount = indices.size();
    this->vao.bind();
    this->vbo = new VertexBuffer(vertices.data(), vertices.size() * sizeof(Vertex));
    this->ebo = new IndexBuffer(indices.data(), indices.size());

    vao.addAttribute(0, 3, sizeof(Vertex), offsetof(Vertex, position));
    vao.addAttribute(1, 3, sizeof(Vertex), offsetof(Vertex, normal));
    vao.addAttribute(2, 2, sizeof(Vertex), offsetof(Vertex, texCoord));
}

Mesh::~Mesh() {
    delete vbo;
    delete ebo;
}

void Mesh::draw() const {
    vao.bind();
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
}