#ifndef Game_hpp
#define Game_hpp
#include "../Player/Player.hpp"

//* sfml libs
#include <SFML/Graphics.hpp>

//* other libs
#include <iostream>

//* definitions
#define VIEW_H 480.0f

class Game {
   private:
    sf::RenderWindow window;
    sf::View view;
    Player p1;
    void resizeView();
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

   public:
    Game();
    ~Game();
    void run();
};

#endif