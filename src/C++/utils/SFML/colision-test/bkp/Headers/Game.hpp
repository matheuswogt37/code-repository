#ifndef Game_hpp
#define Game_hpp

//* sfml libs
#include <SFML/Graphics.hpp>

//* c++ libs
//#include <iostream>

//* my libs
#include <Global.hpp>

class Game {
   private:
    sf::RenderWindow window;
    sf::View view;

    void processEvents();
    void update(sf::Time deltaTime);
    void render();

   public:
    Game();
    ~Game();
    void run();
};

#endif