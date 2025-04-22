#include "Weapon.hpp"

Weapon::Weapon() {};

Weapon::~Weapon() {};

Weapon::Weapon(std::string type) {
    setType(type);
}

std::string& Weapon::getType(void) {
    std::string& ref = type;
    return (ref);
}

void Weapon::setType(std::string newType) {
    this->type = newType;
}