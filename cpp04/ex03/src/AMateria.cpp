#include "AMateria.hpp"

    AMateria::AMateria() {
        _type = "Default AMateria";
        std::cout << "Default Abstract Materia constructed!" << std::endl;
    }

    AMateria::AMateria(std::string const &type) : _type(type) {
        std::cout << "Abstract Materia type " << _type << " created!" << std::endl;
    }

    AMateria::AMateria(const AMateria &obj) {
        //_type = obj._type; //pay attention, something about deep copy
        std::cout << "Abstract Materia copied" << std::endl;
        *this = obj;
    }

    AMateria &AMateria::operator=(const AMateria &obj) {
        if (this != &obj) {
            _type = obj._type;
            std::cout << "Copy assignment called for Abstract Materia!" << std::endl;
        }
        return *this;
    }

    AMateria::~AMateria() {
        std::cout << "Abstract Materia destructed!" << std::endl;
    }

    std::string const &AMateria::getType() const {
        return (_type);
    }

    void AMateria::use(ICharacter &target) {
        std::cout << "Can't use AMateria at " << target.getName() << std::endl;
    }