//* my libs
#include "Headers/Game.hpp"
#include "Headers/Global.hpp"

Game::Game() : window(sf::VideoMode(VIEW_SIZE_X, VIEW_SIZE_Y), "CasteloVania"), view(sf::Vector2f(0, 0), sf::Vector2f(VIEW_SIZE_X, VIEW_SIZE_Y)) {
    p1.loadTexture("Resources/Textures/alucardSheetSprite.png");
    p1.loadAnim();

    p1.setSpritePos(100.f, 150.f);
}

Game::~Game() {}