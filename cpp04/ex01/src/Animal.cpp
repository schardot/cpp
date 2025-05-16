#include "../include/Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << "Default Animal constructed!" << std::endl;
}

Animal::Animal(const Animal &obj) : _type(obj._type)
{
    std::cout << "Animal copied!" << std::endl;
}

Animal &Animal::operator=(const Animal &obj) {
    if (this != &obj) {
        _type = obj._type;
        std::cout << "Animal copied using copy assignment!" << std::endl;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called!" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Animal sound: <silence>" << std::endl;
}

std::string Animal::getType() const {
    return (_type);
}