#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "button.hpp"

class BaseWindow
{
private:
    static constexpr float dragAreaHeight = 30.0f;

    sf::RenderWindow& mSfmlWindow;
    sf::RectangleShape mBaseRect;
    sf::RectangleShape mDragRect;

    bool mIsDragged = false;
    sf::Vector2f mDragBaseDistance;
    sf::Vector2f mOffset;

protected:
    sf::RenderWindow& getWindow() const { return mSfmlWindow; }
    const sf::RectangleShape& getBaseRect() const { return mBaseRect; }
    const sf::RectangleShape& getDragRect() const { return mDragRect; }

public:
    BaseWindow(sf::RenderWindow& window, sf::FloatRect borders)
        : mSfmlWindow(window)
    {
        mDragRect.setPosition({borders.left, borders.top});
        mDragRect.setSize({borders.width, dragAreaHeight});

        mBaseRect.setPosition({borders.left, borders.top + dragAreaHeight});
        mBaseRect.setSize({borders.width, borders.height - dragAreaHeight});

        mDragRect.setFillColor({200, 200, 200});
        mBaseRect.setFillColor({255, 255, 255});

        mDragBaseDistance = mDragRect.getPosition() - mBaseRect.getPosition();
    }

    virtual bool onMousePressed(sf::Vector2f mousePosition)
    {
        if (mDragRect.getGlobalBounds().contains(mousePosition))
        {
            mIsDragged = true;
            mOffset = mousePosition - mDragRect.getPosition();
        }
        return mIsDragged;
    }

    void onMouseReleased()
    {
        mIsDragged = false;
    }

    virtual void onMouseMoved(sf::Vector2f mousePosition)
    {
        if (mIsDragged)
        {
            mDragRect.setPosition(mousePosition - mOffset);
            mBaseRect.setPosition(mDragRect.getPosition() - mDragBaseDistance);
        }
    }

    virtual void handleEvents(const sf::Event& event)
    {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2f mousePosition = mSfmlWindow.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
            onMousePressed(mousePosition);
        }

        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
        {
            onMouseReleased();
        }

        if (event.type == sf::Event::MouseMoved)
        {
            sf::Vector2f mousePosition = mSfmlWindow.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
            onMouseMoved(mousePosition);
        }
    }

    void setBaseColor(sf::Color c) { mBaseRect.setFillColor(c); }
    void setBaseSize(sf::Vector2f sz) { mBaseRect.setSize(sz); }
    void setDragColor(sf::Color c) { mDragRect.setFillColor(c); }
    void setDragSize(sf::Vector2f sz) { mDragRect.setSize(sz); }

    virtual void setPosition(sf::Vector2f p)
    {
        mBaseRect.setPosition(p);
        mDragRect.setPosition(mBaseRect.getPosition() + mDragBaseDistance);
    }

    virtual void draw() const
    {
        mSfmlWindow.draw(mBaseRect);
        mSfmlWindow.draw(mDragRect);
    }
};

class MessageWindow: public BaseWindow
{
private:
    const sf::Font& font;
    sf::Text mainText;
    sf::Vector2f textOffset;

public:
    MessageWindow(sf::RenderWindow& window, sf::FloatRect borders, const sf::Font& f)
        : BaseWindow(window, borders), font(f), textOffset(10, 5) 
    {
        mainText.setFont(font);
        mainText.setString(L"Перетаскиваем окно");
        mainText.setCharacterSize(10);
        mainText.setFillColor(sf::Color::Black);
        updateTextPosition();
    }

    sf::Text& getText() { return mainText; }

    void updateTextPosition()
    {
        mainText.setPosition(getDragRect().getPosition() + textOffset);
    }

    void onMouseMoved(sf::Vector2f mousePosition) override
    {
        BaseWindow::onMouseMoved(mousePosition);
        updateTextPosition();
    }

    void setPosition(sf::Vector2f p) override
    {
        BaseWindow::setPosition(p);
        updateTextPosition();
    }

    void draw() const override
    {
        BaseWindow::draw();
        getWindow().draw(mainText);
    }
};

class ErrorWindow : public MessageWindow
{
public:
    ErrorWindow(sf::RenderWindow& window, sf::FloatRect borders, const sf::Font& f)
        : MessageWindow(window, borders, f)
    {
        MessageWindow::setBaseColor(sf::Color(255, 200, 200));  
        MessageWindow::setDragColor(sf::Color(220, 100, 100)); 
        getText().setFillColor(sf::Color(150, 0, 0)); 
    }

    void setDragColor(sf::Color) = delete; 
    void setBaseColor(sf::Color) = delete; 
};

class DoneWindow : public MessageWindow
{
public:
    DoneWindow(sf::RenderWindow& window, sf::FloatRect borders, const sf::Font& f)
        : MessageWindow(window, borders, f)
    {
        MessageWindow::setBaseColor(sf::Color(200, 255, 200));
        MessageWindow::setDragColor(sf::Color(100, 220, 100)); 
        getText().setFillColor(sf::Color(0, 150, 0));  
    }

    void setDragColor(sf::Color) = delete; 
    void setBaseColor(sf::Color) = delete; 
};

class QuestionWindow : public BaseWindow
{
private:
    sf::Text mQuestionText;
    std::unique_ptr<Button> mOkButton;
    std::unique_ptr<Button> mCancelButton;
    const sf::Font& mFont;
    sf::Vector2f mTextOffset {20, 20};
    sf::Vector2f mOkButtonOffset {20, -50}; // Относительно нижнего края
    sf::Vector2f mCancelButtonOffset {-100, -50}; // Относительно нижнего края

    void updateElementsPosition()
    {
        const auto& baseRect = getBaseRect().getGlobalBounds();
        
        // Позиция текста относительно базового прямоугольника
        mQuestionText.setPosition(
            baseRect.left + mTextOffset.x,
            baseRect.top + mTextOffset.y
        );

        // Позиции кнопок относительно нижнего правого угла
        float buttonWidth = 80;
        float buttonHeight = 30;
        
        // Создаем кнопки с новыми координатами
        mOkButton.reset(new Button(
            getWindow(),
            {
                baseRect.left + mOkButtonOffset.x,
                baseRect.top + baseRect.height + mOkButtonOffset.y,
                buttonWidth,
                buttonHeight
            },
            const_cast<sf::Font&>(mFont),
            16,
            "Ok"
        ));
        
        mCancelButton.reset(new Button(
            getWindow(),
            {
                baseRect.left + baseRect.width + mCancelButtonOffset.x,
                baseRect.top + baseRect.height + mCancelButtonOffset.y,
                buttonWidth,
                buttonHeight
            },
            const_cast<sf::Font&>(mFont),
            16,
            "Cancel"
        ));
    }

public:
    QuestionWindow(sf::RenderWindow& window, sf::FloatRect borders, const sf::Font& font, const std::string& question)
        : BaseWindow(window, borders),
          mFont(font)
    {
        mQuestionText.setFont(mFont);
        mQuestionText.setString(question);
        mQuestionText.setCharacterSize(16);
        mQuestionText.setFillColor(sf::Color::Black);

        setBaseColor(sf::Color(240, 240, 240));
        setDragColor(sf::Color(200, 200, 200));

        updateElementsPosition();
    }

    void onMouseMoved(sf::Vector2f mousePosition) override
    {
        BaseWindow::onMouseMoved(mousePosition);
        updateElementsPosition();
    }

    void setPosition(sf::Vector2f p) override
    {
        BaseWindow::setPosition(p);
        updateElementsPosition();
    }

    void handleEvents(const sf::Event& event) override
    {
        BaseWindow::handleEvents(event);
        
        if (mOkButton && mOkButton->handleEvent(event))
            std::cout << "Ok" << std::endl;
        
        if (mCancelButton && mCancelButton->handleEvent(event))
            std::cout << "Cancel" << std::endl;
    }

    void draw() const override
    {
        BaseWindow::draw();
        getWindow().draw(mQuestionText);
        if (mOkButton) mOkButton->draw();
        if (mCancelButton) mCancelButton->draw();
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Windows");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("consola.ttf")) {
        return EXIT_FAILURE;
    }

    MessageWindow msgWindow(window, {100, 100, 200, 150}, font);
    ErrorWindow errWindow(window, {100, 300, 200, 150}, font);
    DoneWindow doneWindow(window, {100, 500, 200, 150}, font);
    QuestionWindow qWindow(window, {100, 100, 300, 200}, font, "You want to save changes?");

    msgWindow.getText().setString(L"Обычное окно");
    errWindow.getText().setString(L"Ошибка!");
    doneWindow.getText().setString(L"Готово");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            msgWindow.handleEvents(event);
            errWindow.handleEvents(event);
            doneWindow.handleEvents(event);
            qWindow.handleEvents(event);
        }
        
        window.clear(sf::Color::Black);
        msgWindow.draw();
        errWindow.draw();
        doneWindow.draw();
        qWindow.draw();
        window.display();
    }
}