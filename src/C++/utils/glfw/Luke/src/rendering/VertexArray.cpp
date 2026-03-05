#include "VertexArray.hpp"

VertexArray::VertexArray() {
    glGenVertexArrays(1, &this->vaoID);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &this->vaoID);
}

void VertexArray::bind() const {
    glBindVertexArray(this->vaoID);
}

void VertexArray::unbind() const {
    glBindVertexArray(0);
}

void VertexArray::addAttribute(unsigned int index, int count, int stride, int offset) {
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, count, GL_FLOAT, GL_FALSE, stride, (const void*)(uintptr_t)offset);
}