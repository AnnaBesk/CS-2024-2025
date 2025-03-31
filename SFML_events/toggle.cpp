#include <iostream>
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>

class Toggle {
private:
    sf::CircleShape left_part;
    sf::CircleShape right_part;
    sf::RectangleShape central_part;
    sf::CircleShape main_circle;
    sf::RenderWindow& window;
    sf::Vector2f position;  // Относительные координаты (0-1)
    bool isOn;
    float rad = 20;
    float side = 40;

public:
    Toggle(sf::RenderWindow& win, sf::Vector2f relativePos) 
        : window(win), position(relativePos), isOn(false) {

        isOn = false;
        updatePosition();
    }

    void updatePosition() {
        // Получаем текущие размеры окна
        sf::Vector2f windowSize = static_cast<sf::Vector2f>(window.getSize());
        
        // Вычисляем абсолютные координаты
        sf::Vector2f absolutePos(windowSize.x * position.x, windowSize.y * position.y);
        
        left_part.setRadius(rad);
        left_part.setOrigin(sf::Vector2f{rad, rad});
        left_part.setPosition(absolutePos.x - side, absolutePos.y);

        right_part.setRadius(rad);
        right_part.setOrigin(sf::Vector2f{rad, rad});
        right_part.setPosition(absolutePos.x + side, absolutePos.y);

        central_part.setSize(sf::Vector2f{2 * side, side});
        central_part.setOrigin(sf::Vector2f{side, side / 2});
        central_part.setPosition(absolutePos);

        float s_rad = 0.9 * rad;
        main_circle.setRadius(s_rad);
        main_circle.setFillColor(sf::Color::White);
        main_circle.setOrigin(sf::Vector2f{s_rad, s_rad});

        if (isOn == true){
            left_part.setFillColor(sf::Color(100, 200, 100));
            right_part.setFillColor(sf::Color(100, 200, 100));
            central_part.setFillColor(sf::Color(100, 200, 100));
            main_circle.setPosition(absolutePos.x + side, absolutePos.y);

        } else{
            left_part.setFillColor(sf::Color(150, 150, 150));
            right_part.setFillColor(sf::Color(150, 150, 150));
            central_part.setFillColor(sf::Color(150, 150, 150));
            main_circle.setPosition(absolutePos.x - side, absolutePos.y);
        }
    }

    void draw() {
        window.draw(left_part);
        window.draw(right_part);
        window.draw(central_part);
        window.draw(main_circle);
    }

    bool contains(sf::Vector2f point) {
        return central_part.getGlobalBounds().contains(point) || 
               left_part.getGlobalBounds().contains(point) || 
               right_part.getGlobalBounds().contains(point);
    }

    void toggle() {
        isOn = !isOn;
        
        // Получаем текущие абсолютные координаты
        sf::Vector2f windowSize = static_cast<sf::Vector2f>(window.getSize());
        sf::Vector2f absolutePos(windowSize.x * position.x, windowSize.y * position.y);
        
        if (isOn) {
            main_circle.setPosition(absolutePos.x + side, absolutePos.y);
            central_part.setFillColor(sf::Color(100, 200, 100));
            left_part.setFillColor(sf::Color(100, 200, 100));
            right_part.setFillColor(sf::Color(100, 200, 100));
        } else {
            main_circle.setPosition(absolutePos.x - side, absolutePos.y);
            central_part.setFillColor(sf::Color(150, 150, 150));
            left_part.setFillColor(sf::Color(150, 150, 150));
            right_part.setFillColor(sf::Color(150, 150, 150));
        }
    }

    bool getState() const {
        return isOn;
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "10 Toggles");
    window.setFramerateLimit(60);

    // Создаем 10 тумблеров в два столбца
    std::vector<Toggle> toggles;
    for (int i = 0; i < 10; ++i) {
        float x = (i % 2 == 0) ? 0.25f : 0.75f;  // Два столбца
        float y = 0.1f + (i / 2) * 0.2f;         // 5 рядов
        toggles.emplace_back(window, sf::Vector2f{x, y});
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
                // Обновляем позиции всех тумблеров
                for (auto& toggle : toggles) {
                    toggle.updatePosition();
                }
            }

            if (event.type == sf::Event::MouseButtonPressed && 
                event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePosition = window.mapPixelToCoords(
                    {event.mouseButton.x, event.mouseButton.y});
                // Проверяем все тумблеры
                for (auto& toggle : toggles) {
                    if (toggle.contains(mousePosition)) {
                        toggle.toggle();
                    }
                }
            }
        }
        
        window.clear(sf::Color::Black);
        // Рисуем все тумблеры
        for (auto& toggle : toggles) {
            toggle.draw();
        }
        window.display();
    }
}