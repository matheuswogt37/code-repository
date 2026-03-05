#pragma once
#include <string>
#include <stb/stb_image.h>
#include <iostream>
#include "../../external/glad/include/glad/glad.h"
#include <GLFW/glfw3.h>
class Texture {
    private:
        unsigned int id;
        int width;
        int height;
        int channels;
    public:
        Texture(const std::string &path);
        ~Texture();

        void bind(unsigned int unit = 0) const;
        void unbind() const;
        unsigned int getId() const;
};