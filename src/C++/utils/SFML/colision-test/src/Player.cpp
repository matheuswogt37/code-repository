#include "Headers/Player.hpp"

//! private
void Player::loadTexture(std::string path) {
    if (!this->texture.loadFromFile(path)) {
        std::cout << "ERROR! from load p1 texture!" << std::endl;
    } else {
        this->sprite.setTexture(&this->texture);
        this->sprite.setOrigin(this->texture.getSize().x / 2, this->texture.getSize().y / 2);
    }
};

void Player::updateState(STATES newSt) {
    this->animStateOld = this->animState;
    this->animState = newSt;
};

//! public
Player::Player(std::string path) {
    this->speed = 0.0f;


    this->faceRight = true;

    // todo make player receive texture, not path
    //* load texture and apply
    this->loadTexture(path);

    // todo remove those function, only for tests
    this->anim->setValues(&this->texture, sf::Vector2u(8, 12), 0.5f, 1, 0, 3);
};

void Player::handlePlayerInput(sf::Keyboard::Key k, bool pressed) {
    switch (k)
    {
    case sf::Keyboard::Key::D:
        this->inputMov.mRight = pressed;
        break;
    case sf::Keyboard::Key::A:
        this->inputMov.mLeft = pressed;
        break;
    case sf::Keyboard::Key::S:
        this->inputMov.mDown = pressed;
        break;
    case sf::Keyboard::Key::W:
        this->inputMov.mJump = pressed;
        break;
    default:
        break;
    }    
};

Player::~Player(){};