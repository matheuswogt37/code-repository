#ifndef Game_hpp
#define Game_hpp

//* sfml libs
#include <SFML/Graphics.hpp>

//* c++ libs
//#include <iostream>

//* my libs
#include "Headers/Global.hpp"
#include "Headers/Entity.hpp"

class Game {
   private:
    sf::RenderWindow window;
    sf::View view;
    Entity p1;
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

   public:
    Game();
    ~Game();
    void run();
};

#endif