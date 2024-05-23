#ifndef Game_hpp
#define Game_hpp
#include "../Player/Player.hpp"

//* sfml libs
#include <SFML/Graphics.hpp>

//* other libs
#include <iostream>

class Game {
   private:
    sf::RenderWindow window;
    Player p1;
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

   public:
    Game();
    ~Game();
    void run();
};

#endif