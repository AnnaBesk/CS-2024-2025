#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

float Convert(float degree)
{
    float pi = 3.14159265359;
    return (degree * (pi / 180));
}

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(600, 600), "Moving Circle", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    int radius = 30;
    int Rad = 200;
    float angle = 0;
    float vel_x = 2;
    int angle_vel = 2;

    sf::CircleShape circle(radius);
    circle.setOrigin(radius , radius);
    sf::Color my_own {0, 191, 255};
    circle.setFillColor(my_own);

    circle.setPosition(sf::Vector2f(300, 300 - Rad));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        float new_x = 300 + Rad * cos(Convert(angle));
        float new_y = 300 + Rad * sin(Convert(angle));

        angle += angle_vel;

        if (angle >= 360){
            angle = 0;
        }

        circle.setPosition(new_x, new_y);

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }
}