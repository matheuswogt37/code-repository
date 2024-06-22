#ifndef Player_hpp
#define Player_hpp

//* sfml libs
#include <SFML/Graphics.hpp>

//* c++ libs
#include <iostream>

//* my libs
#include <Headers/Animation.hpp>
#include <Headers/Global.hpp>

class Player {
   private:
    sf::RectangleShape sprite;
    sf::Texture texture;
    Animation *anim;
    E_MOV inputMov;
    bool faceRight;
    STATES animState;
    STATES animStateOld;
    float speed;

    // todo make player receive texture, not path
    void loadTexture(std::string path);
    void updateState(STATES newSt);

   public:
    // todo make receive texture alredy loaded
    Player(std::string path);
    // todo make destructor delete texture when use pointers
    ~Player();
    void handlePlayerInput(sf::Keyboard::Key k, bool pressed);
    void draw(sf::RenderWindow *win);
    sf::Vector2f getPos();
    void updateSprite(float deltaTime);
};

#endif