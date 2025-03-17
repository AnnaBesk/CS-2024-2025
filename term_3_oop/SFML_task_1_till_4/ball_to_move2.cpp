#include <SFML/Graphics.hpp>
#include <iostream>
'''
Сделала так, что когда мы меняем положение мыши - то скорости зануляются
Это показалосб логичнее, так как если просто добавлять к скорости ускорение, напраленное на новое положение мыши, 
то мы улетаем на параболу и не достигаем положения мыши быстро

'''
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Mouse position", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::CircleShape ball(30);
    ball.setOrigin(sf::Vector2f{30, 30});
    ball.setPosition(sf::Vector2f{50, 50});
    ball.setFillColor(sf::Color::Green);

    sf::Vector2f velocity = {0, 0};
    float acc = 0.01;
    
    sf::Vector2f napr_prev = {0, 0};

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
            napr.x = napr.x / length;
            napr.y = napr.y / length;

            if (mousePosition == napr_prev){
                velocity.x += napr.x * acc;
                velocity.y += napr.y * acc; 
                std::cout << velocity.x << " " << velocity.y << std::endl;
            }

            else{
                velocity.x = napr.x * acc;
                velocity.y = napr.y * acc;
            }

            napr_prev = mousePosition;
        }

        ball.move(velocity);
        window.clear(sf::Color::Black);
        window.draw(ball);
        window.display();
    }
}