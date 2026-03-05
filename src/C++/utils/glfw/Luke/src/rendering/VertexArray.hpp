#pragma once
#include "../../external/glad/include/glad/glad.h"
/// @brief vao
class VertexArray {
    private:
        unsigned int id;
    public:
        VertexArray();
        ~VertexArray();
        void bind() const;
        void unbind() const;
        void addAttribute(unsigned int index, int count, int stride, int offset);
};