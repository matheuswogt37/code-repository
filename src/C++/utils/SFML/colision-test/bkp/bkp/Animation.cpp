#include "Headers/Animation.hpp"

Animation::Animation(sf::Texture *text, sf::Vector2u imgCount, float switchTime, unsigned int x, unsigned int startImg, unsigned int endImg) {
    this->imgCount = imgCount;
    this->switchTime = switchTime;
    this->totalTime = 0.0f;
    this->img.x = x;
    this->uvRect.width = text->getSize().x / float(imgCount.x);
    this->uvRect.height = text->getSize().y / float(imgCount.y);
    this->mod = 1;
    this-> startImg = startImg;
    this->endImg = endImg;
};

Animation::~Animation() {};


//todo remove those two functions, only for tests
Animation::Animation() {};
void Animation::setValues(sf::Texture *text, sf::Vector2u imgCount, float switchTime, unsigned int x, unsigned int startImg, unsigned int endImg) {
    this->imgCount = imgCount;
    this->switchTime = switchTime;
    this->totalTime = 0.0f;
    this->img.x = x;
    this->uvRect.width = text->getSize().x / float(imgCount.x);
    this->uvRect.height = text->getSize().y / float(imgCount.y);
    this->mod = 1;
    this-> startImg = startImg;
    this->endImg = endImg;
};

void Animation::update(int row, float deltaTime, bool faceRight) {
    this->img.y = row;
    // add time that happened
    this->totalTime += deltaTime;
    // if it's time to update the frame
    if (this->totalTime >= this->switchTime) {
        // this update the image
        this->img.x++;

        // if the image reach the end
        if(this->img.x == this->endImg) {
            // "reset" the image count
            this->img.x = this->startImg;
        }

        // "reset" the time counter
        this->totalTime -= this->switchTime;
    }

    //todo i dont know exactly
    this->uvRect.top = this->img.y * this->uvRect.height;

    if (faceRight) {
        this->uvRect.left = this->img.x * this->uvRect.width;
        //todo i dont know exactly
        this->uvRect.width = abs(this->uvRect.width);
    } else {
        this->uvRect.left = (this->img.x + 1) * abs(this->uvRect.width);
        this->uvRect.width = -abs(this->uvRect.width);
    }
};

void Animation::setSwitchTime(float st) {
    this->switchTime = st;
};

void Animation::updateLimitImg(unsigned int newS, unsigned int newF) {
    // update the image limits
    this->startImg = newS;
    this->endImg = newF;
    // "reset" the image X position
    this->img.x = newS;
};