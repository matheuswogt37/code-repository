// #pragma once
// #include <glad/glad.h>

// class IndexBuffer
// {
// private:
//     unsigned int m_ID;
//     unsigned int m_Count;

// public:
//     IndexBuffer(const unsigned int* data, unsigned int count)
//         : m_Count(count)
//     {
//         glGenBuffers(1, &m_ID);
//         glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
//         glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
//     }

//     ~IndexBuffer()
//     {
//         glDeleteBuffers(1, &m_ID);
//     }

//     void bind() const
//     {
//         glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
//     }

//     void unbind() const
//     {
//         glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//     }

//     unsigned int getCount() const { return m_Count; }
// };
#include "IndexBuffer.hpp"

IndexBuffer::IndexBuffer(const unsigned int *data, unsigned int count) {
    this->eboCount = count;

    glGenBuffers(1, &this->eboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->eboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &this->eboID);
}

void IndexBuffer::bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->eboID);
}

void IndexBuffer::unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int IndexBuffer::getCount() const {
    return this->eboCount;
}