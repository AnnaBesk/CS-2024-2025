#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

sf::Color getRandomColor()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<uint8_t> d(0, 255);
    return sf::Color{d(gen), d(gen), d(gen)};
}

class Ball{

public:
    sf::Vector2f mposition;
    sf::Color mcolor = sf::Color::White; 
    float radius = 15;
    
    Ball(){
        //std::cout << "New ball is created" << std::endl;
        }
};


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Balls", sf::Style::Default);
    window.setFramerateLimit(60);

    std::vector<Ball> balls;
    sf::CircleShape circle;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left){
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i{event.mouseButton.x,event.mouseButton.y});
                    Ball new_ball;
                    new_ball.mposition = mousePos;
                    // std::cout << "New ball it is" << std::endl;
                    balls.push_back(new_ball);
                }
            }

            if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Space){
                    for (auto& ball : balls){
                        ball.mcolor = getRandomColor();
                    }
                    // std::cout << "Let's have some fun" << std::endl;
                }
            }

        }

        window.clear(sf::Color::Black);

        for (auto& ball : balls){
            circle.setRadius(ball.radius);
            circle.setOrigin({ball.radius, ball.radius});
            circle.setPosition(ball.mposition);
            circle.setFillColor(ball.mcolor);
            window.draw(circle);
        }

        window.display();
    }
}