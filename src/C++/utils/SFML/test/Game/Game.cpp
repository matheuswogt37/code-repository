#include "Game.hpp"

Game::Game() : window(sf::VideoMode(980, 480), "CasteloVania") {
    // load player resources
    p1.loadTexture("assets/alucardSheetSprite.png");
    p1.loadAnim();

    //p1.setSpriteTex(p1Tex);
    p1.setSpritePos(100.f, 150.f);
    p1.setSpriteScale(0.25f, 0.25f);
}

Game::~Game() {}

void Game::processEvents() {
    sf::Event evnt;
    while (this->window.pollEvent(evnt)) {
        switch (evnt.type) {
            case sf::Event::KeyPressed:
                this->p1.handlePlayerInput(evnt.key.code, true);
                break;
            case sf::Event::KeyReleased:
                this->p1.handlePlayerInput(evnt.key.code, false);
                break;
            case sf::Event::Closed:
                this->window.close();
                break;
            default:
                // do nothing
                break;
        }
    }
}

void Game::update(sf::Time deltaTime) {
    sf::Vector2f mov(0.f, 0.f);
    if (this->p1.getMUp()) {
        mov.y += -100.f;
    }
    if (this->p1.getMDown()) {
        mov.y += 100.f;
    }
    if (this->p1.getMLeft()) {
        mov.x += -100.f;
        this->p1.setSpriteScale(-0.25f, 0.25f);
    }
    if (this->p1.getMRight()) {
        mov.x += 100.f;
        this->p1.setSpriteScale(0.25f, 0.25f);
    }

    this->p1.updateSprite(deltaTime.asSeconds());
    
    this->p1.setSpriteMove(mov * deltaTime.asSeconds());
}

void Game::render() {
    this->window.clear();
    this->window.draw(this->p1.getSprite());
    this->window.display();
}

void Game::run() {
    sf::Clock clk;
    while (this->window.isOpen()) {
        sf::Time deltaTime = clk.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}