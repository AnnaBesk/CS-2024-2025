#include <iostream>
#include <vector>
#include <memory>

class Individual
{
public:
    virtual void speak() const = 0;
    virtual int identification(Individual* p) const = 0;
    virtual ~Individual() = default;
};

class Alice : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Alice" << std::endl;
    }
    int identification(Individual* p) const override
    {
        return 0;
    }
};

class Bob : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Bob" << std::endl;
    }
    int identification(Individual* p) const override
    {
        return 1;
    }
};

class Casper : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Casper" << std::endl;
    }
    int identification(Individual* p) const override
    {
        return 2;
    }
};

std::vector<std::unique_ptr<Individual>> createIndividuals(){
    std::vector<std::unique_ptr<Individual>> people;

    for (int i = 0; i < 3; i++){
        people.push_back(std::make_unique<Alice>());
    }

    for (int i = 0; i < 2; i++){
        people.push_back(std::make_unique<Bob>());
    }

    for (int i = 0; i < 4; i++){
        people.push_back(std::make_unique<Casper>());
    }

    return people;
}

void letThemSpeak(const std::vector<std::unique_ptr<Individual>>& people){
    for (const auto& person: people){
        person->speak();
    }
}

int identification_2(Individual* p) {
    if (dynamic_cast<Alice*>(p)) {
        return 0;
    } else if (dynamic_cast<Bob*>(p)) {
        return 1;
    } else if (dynamic_cast<Casper*>(p)) {
        return 2;
    }
    return -1; // На случай, если передан nullptr или неизвестный тип
}

int identification_3(Individual* p) {
    if (!p) return -1;
    
    const std::type_info& info = typeid(*p);
    if (info == typeid(Alice)) return 0;
    if (info == typeid(Bob)) return 1;
    if (info == typeid(Casper)) return 2;
    return -1;
}


int main()
{
    std::vector<std::unique_ptr<Individual>> p = createIndividuals();
    letThemSpeak(p);

}