#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Moving Ball", sf::Style::Default);
    window.setFramerateLimit(60);
    
    sf::CircleShape ball(30);
    ball.setOrigin(sf::Vector2f{30, 30});
    ball.setPosition(sf::Vector2f{50, 50});

    float vel = 2;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            ball.move(sf::Vector2f{vel, 0});
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            ball.move(sf::Vector2f{-vel, 0});
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            ball.move(sf::Vector2f{0, -vel});
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            ball.move(sf::Vector2f{0, vel});
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