#include "Player.hpp"

Player::Player() {
    this->mUp = false;
    this->mDown = false;
    this->mLeft = false;
    this->mRight = false;
    this->animState = 1;
    this->speed = 10.0f;
    this->faceRight = true;
    this->sprite.setSize(sf::Vector2f(300.0f, 450.0f));
}

Player::Player(std::string path) {
    this->mUp = false;
    this->mDown = false;
    this->mLeft = false;
    this->mRight = false;
    this->animState = 1;
    this->speed = 10.0f;
    this->faceRight = true;
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

void Player::draw(sf::RenderWindow *win) {
    win->draw(this->sprite);
};

void Player::loadTexture(std::string path) {
    if (!this->texture.loadFromFile(path)) {
        std::cout << "ERROR! from load p1 texture!" << std::endl;
    } else {
        std::cout << "SUCESS! from load p1 texture!" << std::endl;
    }
    this->sprite.setTexture(&this->texture);
    this->sprite.setOrigin(this->texture.getSize().x / 2, this->texture.getSize().y / 2);
}

void Player::loadAnim() {
    // set values to animation
    this->anim.setValues(&this->texture, sf::Vector2u(8, 2), 0.5f);
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

sf::Vector2f Player::getPos() {
    return this->sprite.getPosition();
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

void Player::setSpriteOriginCenter() {
    this->sprite.setOrigin(this->sprite.getSize().x / 2, this->sprite.getSize().y / 2);
}

void Player::setFaceRight(bool newFR) {
    this->faceRight = newFR;
}

void Player::updateSprite(float deltaTime) {
    // switch (this->animState) {
    //     case 0:
    //         // run
    //         anim.setSwitchTime(0.2f);
    //         anim.updateLimitImage(0, 8);
    //         break;

    //     case 1:
    //         // idle
    //         anim.setSwitchTime(0.5f);
    //         anim.updateLimitImage(0, 3);
    //         break;

    //     default:
    //         break;
    // }

    sf::Vector2f mov(0.0f, 0.0f);

    this->animState = 1;

    //* handle player inputs
    if (this->mUp) {
        mov.y += -100.f;
    }
    if (this->mDown) {
        mov.y += 100.f;
    }
    if (this->mLeft) {
        mov.x += -100.f;
    }
    if (this->mRight) {
        mov.x += 100.f;
    }

    //* gravity
    if (0.f == mov.y) {
        mov.y += 75.f;
    }

    if (this->mRight) {
        mov.x += -(this->speed * deltaTime);
        this->animState = 0;
    }
    if (this->mLeft) {
        mov.x += this->speed * deltaTime;
        this->animState = 0;
    }

    if (mov.x < 0.0f)
        this->faceRight = false;
    else if (mov.x > 0.0f)
        this->faceRight = true;

    // switch animation states
    switch (this->animState) {
        case 0:  // run
            if (0 != animStateOld) {
                anim.setSwitchTime(0.2f);
                anim.updateLimitImage(0, 8);
            }
            break;
        case 1:  // idle
            if (1 != animStateOld) {
                anim.setSwitchTime(0.5f);
                anim.updateLimitImage(0, 3);
            }
            break;

        default:
            break;
    }
    this->animStateOld = this->animState;

    this->anim.update(animState, deltaTime, this->faceRight);
    this->sprite.setTextureRect(this->anim.uvRect);
    this->setSpriteMove(mov * deltaTime);
}