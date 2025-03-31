#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Keyboard Pressed 1 - event", sf::Style::Default);
    window.setFramerateLimit(60);
    
    float radius = 100;
    sf::CircleShape ball(radius);
    ball.setOrigin(sf::Vector2f{radius, radius});
    ball.setPosition(sf::Vector2f{400, 400});
    ball.setFillColor(sf::Color::Green);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Space){
                    ball.setFillColor(sf::Color::Red);
                }
            }

            if (event.type == sf::Event::KeyReleased){
                if (event.key.code == sf::Keyboard::Space){
                    ball.setFillColor(sf::Color::Green);
                }
            }

        }

        window.clear(sf::Color::Black);
        window.draw(ball);

        window.display();
    }
}