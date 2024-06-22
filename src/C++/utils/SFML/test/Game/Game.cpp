#include "Game.hpp"

Game::Game() : window(sf::VideoMode(980, 480), "CasteloVania"), view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(980.0f, 480.0f)) {
    // load player resources
    p1.loadTexture("assets/richter-belmont-with-animation.png");
    p1.loadAnim();

    
    //* player sprite origin
    p1.setSpriteOriginCenter();

    // p1.setSpriteTex(p1Tex);
    //* set player initial position
    //! default
    // p1.setSpritePos(100.f, 150.f);
    //! zero coords
    p1.setSpritePos(0.f, 0.f);
    //! middle screen


    p1.setSpriteScale(0.5f, 0.5f);

    
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

    this->p1.updateSprite(deltaTime.asSeconds());
}

void Game::render() {
    this->window.clear();
    // this->view.setCenter(this->p1.getPos());
    this->window.setView(this->view);
    this->p1.draw(&this->window);
    //* output coords
    std::cout << "(" << this->p1.getPos().x << ", " << this->p1.getPos().y << ")" << std::endl;
    //* end output coords
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