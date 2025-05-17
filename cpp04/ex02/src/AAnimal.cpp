#include "../include/AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
    std::cout << "Default AAnimal constructed!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &obj) : _type(obj._type)
{
    std::cout << "AAnimal copied!" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &obj) {
    if (this != &obj) {
        _type = obj._type;
        std::cout << "AAAnimal copied using copy assignment!" << std::endl;
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called!" << std::endl;
}

void AAnimal::makeSound() const {
    std::cout << "AAnimal sound: <silence>" << std::endl;
}

std::string AAnimal::getType() const {
    return (_type);
}