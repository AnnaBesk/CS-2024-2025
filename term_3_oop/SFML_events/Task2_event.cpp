#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Mouse inside 2 - event", sf::Style::Default);
    window.setFramerateLimit(60);
    
    float x_side = 200;
    float y_side = 100;
    sf::RectangleShape rect(sf::Vector2f{x_side, y_side});
    rect.setOrigin(sf::Vector2f{x_side / 2, y_side / 2});
    rect.setPosition(sf::Vector2f{400, 400});
    rect.setFillColor(sf::Color::Green);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseMoved){
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i{event.mouseMove.x,event.mouseMove.y});
                if (rect.getGlobalBounds().contains(mousePos)) {
                    rect.setFillColor(sf::Color::Red);
                }
                else{
                    rect.setFillColor(sf::Color::Green);
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(rect);

        window.display();
    }
}