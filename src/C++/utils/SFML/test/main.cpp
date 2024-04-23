#include <SFML/Graphics.hpp>

void playGame(sf::RenderWindow &window)
{
    sf::Event event;
    sf::RectangleShape rectShape(sf::Vector2f(100.f, 150.f));
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }

    window.clear();
    window.draw(rectShape);
    window.display();
}

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(1280, 720), "CasteloVania");

    while (window.isOpen())
    {
        playGame(window);
    }

    return 0;
}