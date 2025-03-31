#include <iostream>
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Slider
{
protected:
    sf::RectangleShape mTrackShape {};
    sf::RectangleShape mThumbShape {};

    // Когда слайдер находится в нажатом состоянии, 
    // то isPressed = true (Пользователь зажал thumb и держит)
    bool mIsPressed {false};

    // Также храним ссылку на окно SFML, на которое будем отрисовывать слайдер
    // Эту ссылку можно было не хранить, а просто передавать во все функции,
    // где окно понадобится, но тогда код был бы более громоздким
    sf::RenderWindow& mRenderWindow;

public:

    // Конструктор: ссылки нужно обязательно инициализировать в списке инициализации
    Slider(sf::RenderWindow& window, sf::Vector2f centerPosition, sf::Vector2f trackSize, sf::Vector2f thumbSize) 
            : mRenderWindow(window)
    {
        mTrackShape.setSize(trackSize);
        mTrackShape.setOrigin(trackSize / 2.0f);
        mTrackShape.setPosition(centerPosition);
        mTrackShape.setFillColor({200, 200, 220});

        mThumbShape.setSize(thumbSize);
        mThumbShape.setOrigin(thumbSize / 2.0f);
        mThumbShape.setPosition(centerPosition);
        mThumbShape.setFillColor({150, 150, 240});
    }

    // Метод, который рисует кнопку на холсте окна mRenderWindow
    void draw()
    {
        mRenderWindow.draw(mTrackShape);
        mRenderWindow.draw(mThumbShape);
    }

    void setRestrictedThumbPosition(sf::Vector2f position)
    {
        float min = mTrackShape.getPosition().x - mTrackShape.getSize().x / 2.0f;
        float max = mTrackShape.getPosition().x + mTrackShape.getSize().x / 2.0f;
        mThumbShape.setPosition({std::clamp(position.x, min, max), mThumbShape.getPosition().y});
    }

    void onMousePressed(const sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Left) 
        {
            sf::Vector2f mousePosition = mRenderWindow.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
            if (mThumbShape.getGlobalBounds().contains(mousePosition) || mTrackShape.getGlobalBounds().contains(mousePosition)) 
            {
                mIsPressed = true;
                setRestrictedThumbPosition({mousePosition.x, mThumbShape.getPosition().y});
            }
        }
    }

    void onMouseMove(const sf::Event& event)
    {
        if (!mIsPressed)
            return;

        sf::Vector2f mousePosition = mRenderWindow.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
        setRestrictedThumbPosition(mousePosition);
    }

    void onMouseReleased(const sf::Event& event)
    { 
        mIsPressed = false;
    }

    // Нужно вызвать лишь этот метод в цикле обработки событий
    void handleEvent(const sf::Event& event) 
    {
        if (event.type == sf::Event::MouseMoved)
            onMouseMove(event);
        
        else if (event.type == sf::Event::MouseButtonPressed)
            onMousePressed(event);
        
        else if (event.type == sf::Event::MouseButtonReleased)
            onMouseReleased(event);
    }

    bool isPressed() const
    {
        return mIsPressed;
    }

    float getValue() const
    {
        float start = mTrackShape.getPosition().x - mTrackShape.getSize().x / 2.0f;
        float finish = mTrackShape.getPosition().x + mTrackShape.getSize().x / 2.0f;
        float position = mThumbShape.getPosition().x;
        return 255.0f * (position - start) / (finish - start);
    }

};


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Sliders!");
    window.setFramerateLimit(60);

    std::vector <Slider> sliders;
    int col[3] = {128, 128, 128};

    Slider slider_red(window, {250, 200}, {400, 20}, {20, 90});
    Slider slider_green(window, {250, 400}, {400, 20}, {20, 90});
    Slider slider_blue(window, {250, 600}, {400, 20}, {20, 90});

    float rad_cir = 50;
    sf::CircleShape circle(rad_cir);
    circle.setOrigin(sf::Vector2f{rad_cir, rad_cir});
    circle.setFillColor(sf::Color(128, 128, 128));
    circle.setPosition(sf::Vector2f{600, 400});

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            slider_red.handleEvent(event);
            slider_green.handleEvent(event);
            slider_blue.handleEvent(event);
            
            if (event.type == sf::Event::MouseMoved){
                if (slider_red.isPressed()){
                    col[0] = std::round(slider_red.getValue());
                }
                else if (slider_green.isPressed()){
                    col[1] = std::round(slider_green.getValue());
                }
                else if (slider_blue.isPressed()){
                    col[2] = std::round(slider_blue.getValue());
                }
            } 
        }

        window.clear(sf::Color::Black);

        slider_red.draw();
        slider_green.draw();
        slider_blue.draw();

        circle.setFillColor(sf::Color(col[0], col[1], col[2]));
        window.draw(circle);

        window.display();
    }

    return 0;
}