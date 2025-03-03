#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Draggable
{
private:

    sf::RenderWindow& mSfmlWindow;
    sf::RectangleShape mShape   {};
    bool mIsDragged             {false};
    sf::Vector2f mOffset        {0.0f, 0.0f};

public:
    Draggable(sf::RenderWindow& window, sf::Vector2f position, sf::Vector2f size, sf::Color color)
    : mSfmlWindow(window)
    {
        mShape.setPosition(position);
        mShape.setSize(size);
        mShape.setFillColor(color);
    }

    virtual bool onMousePressed(sf::Vector2f mousePosition)
    {
        if (mShape.getGlobalBounds().contains(mousePosition))
        {
            mIsDragged = true;
            mOffset = mousePosition - mShape.getPosition();
        }
        return mIsDragged;
    }

    virtual void onMouseReleased()
    {
        mIsDragged = false;
    }

    void onMouseMoved(sf::Vector2f mousePosition)
    {
        if (mIsDragged)
        {
            mShape.setPosition(mousePosition - mOffset);
        }
    }

    void handleEvents(const sf::Event& event)
    {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2f mousePosition = mSfmlWindow.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
            onMousePressed(mousePosition);
        }

        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2f mousePosition = mSfmlWindow.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
            onMouseReleased();
        }

        if (event.type == sf::Event::MouseMoved)
        {
            sf::Vector2f mousePosition = mSfmlWindow.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
            onMouseMoved(mousePosition);
        }
    }

    void setColor(sf::Color c)
    {
        mShape.setFillColor(c);
    }

    void setSize(sf::Vector2f sz)
    {
        mShape.setSize(sz);
    }

    void setPosition(sf::Vector2f p)
    {
        mShape.setPosition(p);
    }

    void draw() const
    {
        mSfmlWindow.draw(mShape);
    }
};

class DraggableWithColor: public Draggable
{
private:
    sf::Color mBaseColor;
    sf::Color mDragColor;
public:
    DraggableWithColor(sf::RenderWindow& window, sf::Vector2f position, sf::Vector2f size, sf::Color basecolor, sf::Color dragcolor)
        : Draggable(window, position, size, basecolor), mBaseColor(basecolor), mDragColor(dragcolor)
    {
    }

    bool onMousePressed(sf::Vector2f mousePosition) override
    {
        if (Draggable::onMousePressed(mousePosition))
        {
            setColor(mDragColor);
            return true;
        }  
        return false;
    }

    void onMouseReleased() override
    {
        setColor(mBaseColor);
        Draggable::onMouseReleased();
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Draggable");
    window.setFramerateLimit(60);

    DraggableWithColor d {window, {100, 100}, {200, 400}, {80, 80, 120}, {200, 0, 200}};

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            d.handleEvents(event);
        }
        
        window.clear(sf::Color::Black);
        d.draw();
        window.display();
    }
}