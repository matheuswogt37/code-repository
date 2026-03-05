#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer(const void* data, unsigned int size) {
    glGenBuffers(1, &this->id);
    glBindBuffer(GL_ARRAY_BUFFER, this->id);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_COPY);
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &this->id);
}

void VertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, this->id);
}
void VertexBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}