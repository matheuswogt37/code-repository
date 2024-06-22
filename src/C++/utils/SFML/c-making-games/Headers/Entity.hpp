#ifndef Entity_hpp
#define Entity_hpp

#include <SFML/Graphics.hpp>
#include <string>

#include "Animation.hpp"

class Entity {
    private:
        sf::RectangleShape sprite;
        sf::Texture *text;
        Animation *anim;
        int stateAnim;
        int stateAnimOld;
        bool faceRight;

    public:
        Entity(std::string textPath);
        ~Entity();
        void draw(sf::RenderWindow *win);
        void loadTexture(std::string textPath);
        void loadAnim();
        sf::Vector2f getPos();
        void setSpritePos(float x, float y);
        void setSpriteMove(sf::Vector2f move);
        void setFaceRight(bool newFR);
        void updateSprite(float deltaTime);
};

#endif