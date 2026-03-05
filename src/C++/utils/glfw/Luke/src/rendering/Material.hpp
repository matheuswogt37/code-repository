#pragma once
#include <memory>
#include <vector>
#include "Shader.hpp"
#include "Texture.hpp"

class Material {
    private:
        std::shared_ptr<Shader> shader;
        std::vector<std::shared_ptr<Texture>> textures;
    public:
        Material(std::shared_ptr<Shader> shader);
        Shader &getShader();
        void addTexture(std::shared_ptr<Texture> texture);
        void bind();
        void unbind();
};