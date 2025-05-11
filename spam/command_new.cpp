#include <random>
#include <cstdlib>
#include <vector>
#include <memory>
#include <algorithm>
#include "SFML/Graphics.hpp"

float getRandomFloat(float min, float max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> d(min, max);
    return d(gen);
}

float getRandomInt(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> d(min, max);
    return d(gen);
}

sf::Color getRandomColor()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<sf::Uint8> d;
    return sf::Color(d(gen), d(gen), d(gen));
}

class ShapePool
{
protected:
    sf::RectangleShape mField;
    std::vector<sf::Shape*> mShapes;
    sf::RenderWindow& mRenderWindow;

public:

    ShapePool(sf::RenderWindow& window, sf::Vector2f position, sf::Vector2f size)
    : mRenderWindow(window)
    {
        mField.setPosition(position);
        mField.setSize(size);
        mField.setFillColor(sf::Color(0, 100, 200, 40));
    }

    void addShape(sf::Shape* p)
    {
        p->setOrigin(p->getGlobalBounds().getSize() / 2.0f);
        sf::Vector2f min = p->getGlobalBounds().getSize() / 2.0f;
        sf::Vector2f max = mField.getSize() - p->getGlobalBounds().getSize() / 2.0f;
        p->setPosition(mField.getPosition() + sf::Vector2f(getRandomFloat(min.x, max.x), getRandomFloat(min.x, max.y)));
        p->setFillColor(getRandomColor());
        mShapes.push_back(p);
    }

    size_t getNumbeorOfShapes() const {return mShapes.size();}
    sf::Vector2f getPosition() const {return mField.getPosition();}
    sf::Vector2f getSize() const {return mField.getSize();}

    sf::Shape& getShape(int index)
    {
        return *mShapes.at(index);
    }


    void draw() const
    {
        for (auto p : mShapes)
            mRenderWindow.draw(*p);
        mRenderWindow.draw(mField);        
    }

    ~ShapePool()
    {
        for (auto* p : mShapes)
            delete p;
    }
    friend class DeleteCommand; 

};

class Command {
    public:
        virtual void execute() = 0;
        virtual void unexecute() = 0;
        virtual std::unique_ptr<Command> clone() const = 0;
        virtual ~Command() = default;
};

class NoCommand : public Command
{
public:
    void execute() override {};
};

class ControlPanel {
protected:
    std::vector<Button*> mButtons;
    std::vector<std::unique_ptr<Command>> mCommands;
    std::vector<std::unique_ptr<Command>> mCommandHistory;
    sf::RenderWindow& mRenderWindow;

public:
    ControlPanel(sf::RenderWindow& window) : mRenderWindow(window) {}

    void addButton(Button* pb, std::unique_ptr<Command> pc) {
        mButtons.push_back(pb);
        mCommands.push_back(std::move(pc));
    }

    void undoLastCommand() {
        if (!mCommandHistory.empty()) {
            mCommandHistory.back()->unexecute();
            mCommandHistory.pop_back();
        }
    }

    void handleEvent(sf::Event event) {
        for (size_t i = 0; i < mButtons.size(); ++i) {
            if (mButtons[i]->handleEvent(event)) {
                mCommands[i]->execute();
                
                // Не сохраняем UndoCommand в историю!
                if (dynamic_cast<UndoCommand*>(mCommands[i].get()) == nullptr) {
                    mCommandHistory.push_back(mCommands[i]->clone());
                }
            }
        }
    }
    
    size_t getNumberOfButtons() const {return mButtons.size();}

    void draw()
    {
        for (auto p : mButtons)
            p->draw();
    }

    ~ControlPanel()
    {
        for (auto p : mButtons)
            delete p;
        for (auto p : mCommands)
            delete p;
    }

};

class UndoCommand : public Command {
    ControlPanel& mControlPanel;
public:
    UndoCommand(ControlPanel& panel) : mControlPanel(panel) {}
    
    void execute() override { 
        mControlPanel.undoLastCommand(); 
    }
    
    void unexecute() override {}
    
    std::unique_ptr<Command> clone() const override {
        return std::make_unique<UndoCommand>(*this);
    }
};

class RotateCommand : public Command {
    ShapePool& mPool;
    size_t mIndex;
    float mAngle;
public:
    RotateCommand(ShapePool& pool, size_t index, float angle)
        : mPool(pool), mIndex(index), mAngle(angle) {}

    void execute() override { mPool.getShape(mIndex).rotate(mAngle); }
    void unexecute() override { mPool.getShape(mIndex).rotate(-mAngle); }
    
    std::unique_ptr<Command> clone() const override {
        return std::make_unique<RotateCommand>(*this);
    }
};

class RandomColorCommand : public Command
{
protected:
    ShapePool& mPool;
    size_t mIndex;
    sf::Color mOldColor;
    sf::Color mNewColor;

public:
    RandomColorCommand(ShapePool& pool, size_t index) 
        : mPool(pool), mIndex(index) {
            mOldColor = mPool->getShape(mIndex)->getFillColor();
        }

    void execute() override
    {
        mNewColor = getRandomColor();
        mPool.getShape(mIndex).setFillColor(mNewColor);
    }
    
    void unexecute() override
    {
        mPool.getShape(mIndex).setFillColor(mOldColor);
    }

    std::unique_ptr<Command> clone() const override {
        return std::make_unique<RandomColorCommand>(*this);
    }

};

class AddNewRandomShape : public Command {
    ShapePool& mPool;
    float mMinSize, mMaxSize;
    sf::Shape* mAddedShape = nullptr;
    
public:
    AddNewRandomShape(ShapePool& pool, float minSize, float maxSize)
        : mPool(pool), mMinSize(minSize), mMaxSize(maxSize) {}

    void execute() override {
        int r = getRandomInt(0, 2);
        sf::Shape* ps;
        if (r == 0)
            ps = new sf::RectangleShape{sf::Vector2f{getRandomFloat(mMaxSize, mMaxSize), getRandomFloat(mMaxSize, mMaxSize)}};
        else if (r == 1)
            ps = new sf::CircleShape{getRandomFloat(mMaxSize / 2, mMaxSize / 2)};
        else
            ps = new sf::CircleShape{getRandomFloat(mMaxSize / 2, mMaxSize / 2), 3};

        ps->setFillColor(getRandomColor());
        ps->rotate(getRandomFloat(0, 360));
        sf::FloatRect bounds = ps->getGlobalBounds();
        ps->setPosition({mPool.getPosition().x + getRandomFloat(0, mPool.getSize().x - bounds.width),
                         mPool.getPosition().y + getRandomFloat(0, mPool.getSize().y - bounds.height)
        });
        mAddedShape = ps;
        mPool.addShape(ps);
    }

    void unexecute() override {
        if (mAddedShape) {
            auto& shapes = mPool.mShapes;
            shapes.erase(std::remove(shapes.begin(), shapes.end(), mAddedShape), shapes.end());
            delete mAddedShape;
        }
    }

    std::unique_ptr<Command> clone() const override {
        auto cmd = std::make_unique<AddNewRandomShape>(*this);
        cmd->mAddedShape = nullptr;
        return cmd;
    }
};

class AllRandomColorCommand : public Command
{
protected:
    ShapePool& mPool;

public:
    AllRandomColorCommand(ShapePool& pool) 
        : mPool(pool) {}

    void execute() override
    {
        for (size_t i = 0; i < mPool.getNumbeorOfShapes(); ++i)
        {
            mPool.getShape(i).setFillColor(getRandomColor());
        }
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Shapes and Command");
    ShapePool pool(window, {300, 50}, {450, 700});
    ControlPanel control(window);

    // Добавляем кнопки
    control.addButton(
        new Button(window, {40, 80, 240, 40}, font, "Rotate First"),
        std::make_unique<RotateCommand>(pool, 0, 30)
    );
    
    control.addButton(
        new Button(window, {40, 700, 240, 40}, font, "Undo"),
        std::make_unique<UndoCommand>(control)
    );

    // ... (остальные кнопки)

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            control.handleEvent(event);
        }
        window.clear();
        pool.draw();
        control.draw();
        window.display();
    }
}