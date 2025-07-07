#include "../include/Cat.hpp"

Cat::Cat()
{
    catBrain = new Brain();
    _type = "Cat";
    std::cout << "Default Cat constructed!" << std::endl;
};

Cat::Cat(const Cat &obj) : Animal(obj)
{
    _type = "Cat";
    if (obj.catBrain)
        catBrain = new Brain(*obj.catBrain);
    else
        catBrain = NULL;
    std::cout << "Cat copied!" << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
    if (this != &obj)
    {
        Animal::operator=(obj);
        if (catBrain)
            delete catBrain;
        if (obj.catBrain)
            catBrain = new Brain(*obj.catBrain);
        else
            catBrain = NULL;
        std::cout << "Dog copied using copy assignment!" << std::endl;
    }
    return *this;
}

Cat::~Cat()
{
    delete catBrain;
    std::cout << "Cat destructor called!" << std::endl;
};

void Cat::makeSound() const
{
    std::cout << "Cat sound: *meows softly*" << std::endl;
}

Brain *Cat::getBrain() const
{
    return catBrain;
}
