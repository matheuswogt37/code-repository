#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer(const void* data, unsigned int size) {
    glGenBuffers(1, &this->vboID);
    glBindBuffer(GL_ARRAY_BUFFER, this->vboID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_COPY);
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &this->vboID);
}

void VertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, this->vboID);
}
void VertexBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}