#include "../include/Cure.hpp"

Cure::Cure() : AMateria("cure") {
    _type = "cure";
    std::cout << "Default Cure constructed!" << std::endl;
}

Cure::Cure(const Cure &obj) : AMateria(obj) {
    //_type = obj._type; // pay attention, something about deep copy
    std::cout << "Cure copied" << std::endl;
}

Cure &Cure::operator=(const Cure &obj) {
    if (this != &obj) {
        AMateria::operator=(obj);
        std::cout << "Copy assignment called for Cure!" << std::endl;
    }
    return *this;
}

Cure::~Cure() {
    std::cout << "Cure destructed!" << std::endl;
}

AMateria *Cure::clone() const {
    return (new Cure(*this));
}

void Cure::use(ICharacter &target){
    std::cout << "* heals " << target.getName() << "’s wounds * " << std::endl;
}