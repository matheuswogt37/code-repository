#ifndef Player_hpp
#define Player_hpp
//* other libs
#include <iostream>

//* sfml libs
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

//* my libs
#include "../Animation/Animation.hpp"

class Player {
    private:
        sf::RectangleShape sprite;
        Animation anim;
        int animState;
        int animStateOld;
        float speed;
        bool faceRight;
        sf::Texture texture;
        bool mUp;
        bool mDown;
        bool mLeft;
        bool mRight;
    public:
        Player();
        Player(std::string path);
        ~Player();
        void handlePlayerInput(sf::Keyboard::Key k, bool pressed);
        void draw(sf::RenderWindow *win);
        void loadTexture(std::string path);
        void loadAnim();
        bool getMUp();
        bool getMDown();
        bool getMLeft();
        bool getMRight();
        sf::Vector2f getPos();
        void setSpritePos(float x, float y);
        void setSpriteScale(float x, float y);
        void setSpriteMove(sf::Vector2f mov);
        void setSpriteOriginCenter();
        void setFaceRight(bool newFR);
        void updateSprite(float deltaTime);
};
#endif