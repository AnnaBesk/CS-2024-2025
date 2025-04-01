#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <algorithm>

class DropList {
private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::RectangleShape mainButton;
    sf::Text mainButtonText;
    std::vector<sf::RectangleShape> options;
    std::vector<sf::Text> optionsText;
    std::vector<std::wstring> items;
    bool isOpen = false;
    unsigned int selectedIndex = 0;

public:
    DropList(sf::RenderWindow& win, const sf::Font& f, const sf::Vector2f& position, 
             const sf::Vector2f& size, const std::vector<std::wstring>& itemsList)
        : window(win), font(f), items(itemsList) {
        
        // основная кнопка
        mainButton.setSize(size);
        mainButton.setPosition(position);
        mainButton.setFillColor(sf::Color(180, 210, 210));
        mainButton.setOutlineThickness(1);
        mainButton.setOutlineColor(sf::Color::Black);

        mainButtonText.setFont(font);
        mainButtonText.setString(items.empty() ? L"" : items[0]);
        mainButtonText.setCharacterSize(20);
        mainButtonText.setFillColor(sf::Color::Black);
        mainButtonText.setPosition(
            position.x + 10, 
            position.y + (size.y - mainButtonText.getLocalBounds().height) / 2
        );

        // варианты ответов
        for (size_t i = 0; i < items.size(); ++i) {
            sf::RectangleShape option(size);
            option.setPosition(position.x, position.y + size.y * (i + 1));
            option.setFillColor(sf::Color(220, 250, 250));
            option.setOutlineThickness(1);
            option.setOutlineColor(sf::Color::Black);
            options.push_back(option);

            sf::Text text;
            text.setFont(font);
            text.setString(items[i]);
            text.setCharacterSize(20);
            text.setFillColor(sf::Color::Black);
            text.setPosition(
                position.x + 10, 
                position.y + size.y * (i + 1) + (size.y - text.getLocalBounds().height) / 2
            );
            optionsText.push_back(text);
        }
    }

    void handleEvent(const sf::Event& event) {
        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2f mousePos = window.mapPixelToCoords(
                {event.mouseButton.x, event.mouseButton.y});

            if (mainButton.getGlobalBounds().contains(mousePos)) {
                isOpen = !isOpen;
            }

            else if (isOpen) {
                for (size_t i = 0; i < options.size(); ++i) {
                    if (options[i].getGlobalBounds().contains(mousePos)) {
                        selectedIndex = i;
                        mainButtonText.setString(items[i]);
                        isOpen = false;
                        break;
                    }
                }
            }
        }
    }

    void draw() {
        window.draw(mainButton);
        window.draw(mainButtonText);

        if (isOpen) {
            for (auto& option : options) {
                window.draw(option);
            }
            for (auto& text : optionsText) {
                window.draw(text);
            }
        }
    }

    unsigned int getSelectedIndex() const {
        return selectedIndex;
    }

    const std::wstring& getSelectedItem() const {
        return items[selectedIndex];
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "DropList");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("consola.ttf")) {
        return EXIT_FAILURE;
    }

    std::vector<std::wstring> shapes = {L"Круг", L"Квадрат", L"Треугольник"};
    DropList dropList(window, font, {50, 50}, {200, 40}, shapes);

    sf::CircleShape circle(100);
    circle.setPosition(350, 250);
    circle.setFillColor(sf::Color::Green);

    sf::RectangleShape square({200, 200});
    square.setPosition(300, 200);
    square.setFillColor(sf::Color::Red);

    sf::CircleShape triangle(100, 3);
    triangle.setPosition(350, 250);
    triangle.setFillColor(sf::Color::Blue);

    sf::Shape* currentShape = &circle;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            dropList.handleEvent(event);
        }

        switch (dropList.getSelectedIndex()) {
            case 0: currentShape = &circle; break;
            case 1: currentShape = &square; break;
            case 2: currentShape = &triangle; break;
        }

        window.clear(sf::Color::Black);
        dropList.draw();
        window.draw(*currentShape);
        window.display();
    }

    return 0;
}