#include "Material.hpp"

Material::Material(std::shared_ptr<Shader> shader) : shader(shader) {}

Shader &Material::getShader() {
    return *this->shader;
}

void Material::addTexture(std::shared_ptr<Texture> texture) {
    this->textures.push_back(texture);
}

void Material::setColor(glm::vec3 color) {
    this->color = color;
}

void Material::bind() {
    this->shader->bind();

    this->shader->setVec3("u_Color", this->color);

    for (size_t i = 0; i < this->textures.size(); i++) {
        this->textures[i]->bind(i);
    }
}

void Material::unbind() {
    for (size_t i = 0; i < this->textures.size(); i++) {
        this->textures[i]->unbind();
    }
}