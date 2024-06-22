#include "Headers/Entity.hpp"

Entity::Entity(std::string textPath) {

}

Entity::~Entity() {

}

void Entity::draw(sf::RenderWindow *win) {
    
}

void Entity::loadTexture(std::string textPath) {
    if (!this->text->loadFromFile(path)) {
        std::cout << "ERROR! from load p1 texture!" << std::endl;
    } else {
        std::cout << "SUCESS! from load p1 texture!" << std::endl;
    }
    this->sprite->setTexture(this->text);
    this->sprite->setOrigin(this->texture->getSize().x / 2, this->texture->getSize().y / 2);
}

void loadAnim() {
    this->anim->setValues(this->text, sf::Vector2u(8, 2), 0.5f);
}

sf::Vector2f getPos();
void loadAnim();
void setSpritePos(float x, float y);
void setSpriteMove(sf::Vector2f move);
void setFaceRight(bool newFR);
void updateSprite(float deltaTime);