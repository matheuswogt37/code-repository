#include "Animation.hpp"


//todo apagar dps
#include <iostream>

Animation::Animation() {};

Animation::Animation(sf::Texture *text, sf::Vector2u imCount, float swTime) {
    this->imageCount = imCount;
    this->switchTime = swTime;
    this->totalTime = 0.0f;
    this->image.x = 0;
    this->uvRect.width = text->getSize().x / float(imageCount.x);
    this->uvRect.height = text->getSize().y / float(imageCount.y);
    this->modifier = 1;
    this->initImage = 0;
    this->finalImage = 3;
};

Animation::~Animation(){};

void Animation::update(int row, float deltaTime, bool faceRight) {
    this->image.y = row;
    this->totalTime += deltaTime;
    if (this->totalTime >= this->switchTime) {
        this->totalTime -= this->switchTime;
        this->image.x++;
        if (this->image.x == this->finalImage) {
            this->image.x = this->initImage;
        }
    }

    this->uvRect.top = this->image.y * this->uvRect.height;

    if (faceRight) {
        this->uvRect.left = this->image.x * this->uvRect.width;
        this->uvRect.width = abs(this->uvRect.width);
    } else {
        this->uvRect.left = (this->image.x + 1) * abs(this->uvRect.width);
        this->uvRect.width = -abs(this->uvRect.width);
    }

};

void Animation::setValues(sf::Texture *text, sf::Vector2u imCount, float swTime) {
    this->imageCount = imCount;
    this->switchTime = swTime;
    this->totalTime = 0.0f;
    this->image.x = 0;
    this->uvRect.width = text->getSize().x / float(imageCount.x);
    this->uvRect.height = text->getSize().y / float(imageCount.y);
    this->modifier = 1;
    this->initImage = 0;
    this->finalImage = 3;
};

void Animation::setSwitchTime(float newSwT) {
    this->switchTime = newSwT;
}

void Animation::updateLimitImage(int newI, int newF) {
    this->initImage = newI;
    this->finalImage = newF;
    this->image.x = newI;
};