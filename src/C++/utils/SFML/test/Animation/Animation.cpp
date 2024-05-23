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
};

Animation::~Animation(){};

void Animation::update(int row, float deltaTime) {
    this->image.y = row;
    this->totalTime += deltaTime;
    if (this->totalTime >= this->switchTime) {
        this->totalTime -= this->switchTime;
        this->image.x++;
        //!std::cout << "totaltime - " << totalTime << "   \t| - deltaTima - " << deltaTime << "  \t| this->image.x = " << image.x << std::endl;
        if (this->image.x == this->imageCount.x) {
            this->image.x = this->initImage;
        }
    }

    this->uvRect.left = this->image.x * this->uvRect.width;
    this->uvRect.top = this->image.y * this->uvRect.height;
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
};

void Animation::updateInitImage(unsigned int newI) {
    this->initImage = newI;
};