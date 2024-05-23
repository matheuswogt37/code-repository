#include "Player.hpp"

Player::Player() {
    this->mUp = false;
    this->mDown = false;
    this->mLeft = false;
    this->mRight = false;
    this->animState = 0;
    this->sprite.setSize(sf::Vector2f(300.0f, 450.0f));
}

Player::Player(std::string path) {
    this->mUp = false;
    this->mDown = false;
    this->mLeft = false;
    this->mRight = false;
    this->animState = 0;
    this->sprite.setSize(sf::Vector2f(300.0f, 450.0f));

    // load resources
    this->loadTexture(path);
    this->loadAnim();
}

Player::~Player() {}

void Player::handlePlayerInput(sf::Keyboard::Key k, bool pressed) {
    switch (k) {
        case sf::Keyboard::W:
            this->mUp = pressed;
            break;
        case sf::Keyboard::S:
            this->mDown = pressed;
            break;
        case sf::Keyboard::A:
            this->mLeft = pressed;
            break;
        case sf::Keyboard::D:
            this->mRight = pressed;
            break;
        default:
            break;
    }
};

sf::RectangleShape Player::getSprite() {
    return this->sprite;
}

void Player::loadTexture(std::string path) {
    if (!this->texture.loadFromFile(path)) {
        std::cout << "ERROR! from load p1 texture!" << std::endl;
    } else {
        std::cout << "SUCESS! from load p1 texture!" << std::endl;
    }
    this->sprite.setTexture(&this->texture);
    this->sprite.setOrigin(this->texture.getSize().x / 5, this->texture.getSize().y / 5);
}

void Player::loadAnim() {
    // set values to animation
    this->anim.setValues(&this->texture, sf::Vector2u(8, 12), 0.1f);
}

bool Player::getMUp() {
    return this->mUp;
}

bool Player::getMDown() {
    return this->mDown;
}

bool Player::getMLeft() {
    return this->mLeft;
}

bool Player::getMRight() {
    return this->mRight;
}

void Player::setSpritePos(float x, float y) {
    this->sprite.setPosition(x, y);
}

void Player::setSpriteScale(float x, float y) {
    this->sprite.setScale(x, y);
}

void Player::setSpriteMove(sf::Vector2f mov) {
    this->sprite.move(mov);
}

void Player::updateSprite(float deltaTime) {
    this->anim.update(animState, deltaTime);
    this->sprite.setTextureRect(this->anim.uvRect);
}