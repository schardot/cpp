#include "../include/Cat.hpp"

Cat::Cat()
{
    _type = "Cat";
    std::cout << "Default Cat constructed!" << std::endl;
};

Cat::Cat(const Cat &obj) : Animal(obj)
{
    _type = "Cat";
    std::cout << "Cat copied!" << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
    if (this != &obj)
    {
        Animal::operator=(obj);
    }
    std::cout << "Cat copied using copy assignment!" << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called!" << std::endl;
};

void Cat::makeSound() const
{
    std::cout << "Cat sound: *meows softly*" << std::endl;
}
