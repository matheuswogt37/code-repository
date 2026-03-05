#pragma once
#include "../../external/glad/include/glad/glad.h"

/// @brief VBO
class VertexBuffer {
    private:
        unsigned int id;
    public:
        VertexBuffer(const void* data, unsigned int size);
        ~VertexBuffer();
        void bind() const;
        void unbind() const;
};