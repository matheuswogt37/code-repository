#pragma once
#include "../../external/glad/include/glad/glad.h"

/// @brief ebo
class IndexBuffer {
    private:
        unsigned int eboID;
        unsigned int eboCount;
    public:
        IndexBuffer(const unsigned int* data, unsigned int count);
        ~IndexBuffer();
        void bind() const;
        void unbind() const;
        unsigned int getCount() const;
};