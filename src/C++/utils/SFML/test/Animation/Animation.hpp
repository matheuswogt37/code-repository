#ifndef Animation_hpp
#define Animation_hpp

//* sfml libs
#include <SFML/Graphics.hpp>

class Animation {
   private:
    sf::Vector2u imageCount;
    float totalTime;
    float switchTime;
    int modifier;
    unsigned int initImage;

   public:
    sf::Vector2u image;
    sf::IntRect uvRect;
    Animation();
    Animation(sf::Texture *text, sf::Vector2u imCount, float swTime);
    ~Animation();
    void update(int row, float deltaTime);
    void setValues(sf::Texture *text, sf::Vector2u imCount, float swTime);
    void updateInitImage(unsigned int newI);
};

#endif