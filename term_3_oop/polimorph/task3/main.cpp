#include <iostream>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "widget.hpp"
#include "button.hpp"
#include "slider.hpp"
#include "draggable.hpp"



int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Widgets");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("sourceCodePro.ttf")) 
    {
        std::cout << "Error: Font file not found." << std::endl;
        std::exit(1);
    }

    std::vector<Widget*> widgets; // Обычные указатели
    
    widgets.push_back(new Button{window, {350, 300, 200, 80}, font, "Cat"});
    widgets.push_back(new Button{window, {200, 450, 100, 80}, font, "Dog"});
    widgets.push_back(new Button{window, {600, 600, 150, 70}, font, "Mouse"});

    widgets.push_back(new Slider{window, {500, 500}, {200, 10}, {20, 40}});
    widgets.push_back(new Slider{window, {300, 100}, {250, 20}, {30, 60}});

    widgets.push_back(new Draggable{window, {550, 100}, {200, 120}, {20, 120, 50}});
    widgets.push_back(new Draggable{window, {50, 550}, {200, 200}, {170, 20, 50}});
    widgets.push_back(new Draggable{window, {50, 200}, {100, 100}, {100, 20, 150}});

    '''
    # с умными указателями

    std::vector<std::unique_ptr<Widget>> widgets;

    widgets.push_back(std::make_unique<Button>{window, {350, 300, 200, 80}, font, "Cat"});
    widgets.push_back(std::make_unique<Button>{window, {200, 450, 100, 80}, font, "Dog"});
    widgets.push_back(std::make_unique<Button>{window, {600, 600, 150, 70}, font, "Mouse"});

    widgets.push_back(std::make_unique<Button>{window, {500, 500}, {200, 10}, {20, 40}});
    widgets.push_back(std::make_unique<Button>{window, {300, 100}, {250, 20}, {30, 60}});

    widgets.push_back(std::make_unique<Draggable>{window, {550, 100}, {200, 120}, {20, 120, 50}});
    widgets.push_back(std::make_unique<Draggable>{window, {50, 550}, {200, 200}, {170, 20, 50}});
    widgets.push_back(std::make_unique<Draggable>{window, {50, 200}, {100, 100}, {100, 20, 150}});
    '''
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
                
            for (auto& widget : widgets) {
                widget->handleEvent(event); // Полиморфный вызов
            }
        }
    
        window.clear();
        for (auto& widget : widgets) {
            widget->draw(); // Полиморфный вызов
        }
        window.display();
    }

    // Очистка (не забываем удалить объекты!) - с умными указателями не нужно
    for (Widget* widget : widgets) {
        delete widget;
    }
    widgets.clear();
}