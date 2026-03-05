#include "Material.hpp"

Material::Material(std::shared_ptr<Shader> shader) : shader(shader) {}

Shader &Material::getShader() {
    return *this->shader;
}

void Material::addTexture(std::shared_ptr<Texture> texture) {
    this->textures.push_back(texture);
}

void Material::bind() {
    this->shader->bind();

    for (size_t i = 0; i < this->textures.size(); i++) {
        this->textures[i]->bind(i);
    }
}

void Material::unbind() {
    for (size_t i = 0; i < this->textures.size(); i++) {
        this->textures[i]->unbind();
    }
}