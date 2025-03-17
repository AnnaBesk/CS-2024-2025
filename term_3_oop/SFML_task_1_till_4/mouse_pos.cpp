#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 400), "Mouse position", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("consola.ttf"))
    {
        std::cout << "Error! Can't load font!" << std::endl;
        std::exit(1);
    }

    sf::Text text;
    text.setFont(font);
    text.setString(L"Привет!");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition({60, 140});

    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosition = window.mapPixelToCoords(mousePixel);

        text.setString(L"Позиция мыши в пикселях по x: " + std::to_wstring(mousePixel.x) + 
            L"\nПозиция мыши в пикселях по y: " + std::to_wstring(mousePixel.y) + 
            L"\nПозиция мыши в мире объектов по x: " + std::to_wstring(mousePosition.x) +
            L"\nПозиция мыши в мире объектов по y: " + std::to_wstring(mousePosition.y));


        window.clear(sf::Color::Black);
        window.draw(text);
        window.display();
    }
}