#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(400, 400), "Rotating rectangle!", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    sf::RectangleShape rectangle;

    rectangle.setSize(sf::Vector2f(100, 100));
    rectangle.setOrigin(50, 50);

    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition({200, 200});



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        rectangle.rotate(1);
        window.clear(sf::Color::Black);
        window.draw(rectangle);
        window.display();
    }
}