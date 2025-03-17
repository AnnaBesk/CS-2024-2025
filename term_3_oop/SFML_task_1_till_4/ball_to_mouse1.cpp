#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Mouse position", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::CircleShape ball(30);
    ball.setOrigin(sf::Vector2f{30, 30});
    ball.setPosition(sf::Vector2f{50, 50});
    ball.setFillColor(sf::Color::Green);

    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
            sf::Vector2f mousePosition = window.mapPixelToCoords(mousePixel);

            sf::Vector2f napr = mousePosition - ball.getPosition();
            float length = std::sqrt(napr.x * napr.x + napr.y * napr.y); 
            napr.x = napr.x / (length) * 4;
            napr.y = napr.y / (length) * 4;

            ball.move(napr);
        }

        sf::Vector2f max = window.getView().getSize();

        if (ball.getPosition().x - ball.getRadius() > max.x)
            ball.move({-max.x - 2 * ball.getRadius(), 0});

        if (ball.getPosition().x + ball.getRadius() < 0){
            ball.move({max.x + 2 * ball.getRadius(), 0});
        }
        if (ball.getPosition().y - ball.getRadius() > max.y)
            ball.move({0, -max.y - 2 * ball.getRadius()});

        if (ball.getPosition().y + ball.getRadius() < 0)
            ball.move({0, max.y + 2 * ball.getRadius()});
        

        window.clear(sf::Color::Black);
        window.draw(ball);
        window.display();
    }
}