#include "../include/Dog.hpp"

Dog::Dog()
{
    dogBrain = new Brain();
    _type = "Dog";
    std::cout << "Default Dog constructed!" << std::endl;
};

Dog::Dog(const Dog &obj) : Animal(obj)
{
    if (obj.dogBrain)
        dogBrain = new Brain(*obj.dogBrain);
    else
        dogBrain = nullptr;
    std::cout << "Dog copied!" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
    if (this != &obj)
    {
        Animal::operator=(obj);
        if (dogBrain)
            delete dogBrain;
        if (obj.dogBrain)
            dogBrain = new Brain(*obj.dogBrain);
        else
            dogBrain = nullptr;
        std::cout << "Dog copied using copy assignment!" << std::endl;
    }
    return *this;
}

Dog::~Dog()
{
    delete dogBrain;
    std::cout << "Dog destructor called!" << std::endl;
};

void Dog::makeSound() const
{
    std::cout << "Dog sound: *howls dramatically*" << std::endl;
}

Brain *Dog::getBrain() const {
     return dogBrain;
}