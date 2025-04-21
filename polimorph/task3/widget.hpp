#pragma once
#include <SFML/Graphics.hpp>

class Widget {
    public:
        virtual ~Widget() = default; // Виртуальный деструктор для корректного удаления
    
        // Обязательные методы для всех виджетов:
        virtual void draw() const = 0;
        virtual bool handleEvent(const sf::Event& event) = 0;

    };
    