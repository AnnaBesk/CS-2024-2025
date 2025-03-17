#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    sf::RenderWindow window(sf::VideoMode(800, 100), "Moving Circle", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    int radius = 30;
    float vel_x = 2;
    sf::CircleShape circle(radius);

    circle.setOrigin(radius , radius);

    sf::Color my_own {150, 0, 0};
    circle.setFillColor(my_own);

    circle.setPosition(sf::Vector2f(radius + 10, (100 - 2 * radius) / 2 + radius));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        sf::Vector2f pos = circle.getPosition();
        
        std::cout << pos.x << std::endl;

        if (pos.x >= 800 + radius) {
            circle.setPosition(-radius - vel_x,  (100 - 2 * radius) / 2 + radius);
        }
        
        circle.move(sf::Vector2f{vel_x, 0});

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }
}