#ifndef Animation_hpp
#define Animation_hpp

//* sfml libs
#include <SFML/Graphics.hpp>

class Animation {
    private:
        sf::Vector2u imgCount;
        float totalTime;
        float switchTime;
        int mod;
        unsigned int startImg;
        unsigned int endImg;

    public:
        sf::Vector2u img;
        sf::IntRect uvRect;
        Animation(sf::Texture *text, sf::Vector2u imgCount, float switchTime, unsigned int x, unsigned int startImg, unsigned int endImg);
        //todo remove those two functions, only for tests
        Animation();
        void setValues(sf::Texture *text, sf::Vector2u imgCount, float switchTime, unsigned int x, unsigned int startImg, unsigned int endImg);
        ~Animation();
        void update(int row, float deltaTime, bool faceRight);
        void setSwitchTime(float newSwT);
        void updateLimitImg(unsigned int newS, unsigned int newF);
};

#endif