#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << "Default WrongAnimal constructed!" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
    _type = obj._type;
    std::cout << "WrongAnimal copied!" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj) {
    if (this != &obj) {
        *this = obj;
    }
    return *this;
    std::cout << "WrongAnimal copied using copy assignment!" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called!" << std::endl;
};

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound: *moooos in a distance*" << std::endl;
}

std::string WrongAnimal::getType() const {
    return (_type);
}