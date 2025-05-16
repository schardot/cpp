#include "../include/Dog.hpp"

Dog::Dog()
{
    _type = "Dog";
    std::cout << "Default Dog constructed!" << std::endl;
};

Dog::Dog(const Dog &obj) : Animal(obj)
{
    std::cout << "Dog copied!" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
    if (this != &obj)
    {
        Animal::operator=(obj);
        std::cout << "Dog copied using copy assignment!" << std::endl;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called!" << std::endl;
};

void Dog::makeSound() const
{
    std::cout << "Dog sound: *howls dramatically*" << std::endl;
}
