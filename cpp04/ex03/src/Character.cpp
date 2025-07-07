#include "../include/Character.hpp"

Character::Character() : ICharacter() {
    std::cout << "Default Character constructed!" << std::endl;
    for (int i = 0; i < 4; i ++) {
        _inventory[i] = NULL;
    }
}

Character::Character(std::string const &name) : ICharacter(), _name(name) {
    std::cout << "Character " << _name << " created!" << std::endl;
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
}

Character::Character(const Character &obj) {
    this->_name = obj.getName();
    for (int i = 0; i < 4; i ++) {
        _inventory[i] = obj._inventory[i] ? obj._inventory[i]->clone() : NULL;
    }
    std::cout << "Character copied!" << std::endl;
}

Character &Character::operator=(const Character &obj) {
    if (this != &obj) {
        this->_name = obj.getName();
        for (int i = 0; i < 4; i++) {
            if (_inventory[i]) {
                delete _inventory[i];
                _inventory[i] = NULL;
            }
            _inventory[i] = obj._inventory[i] ? obj._inventory[i]->clone() : NULL;
        }
        std::cout << "Copy assignment called for Character!" << std::endl;
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
        {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
    }
    std::cout << "Character destructed!" << std::endl;
}

std::string const &Character::getName() const {
    return (_name);
}

void Character::equip(AMateria *m) {
    if (!m)
        return;
    for (int i = 0; i < 4; ++i)
    {
        if (_inventory[i] == m)
        {
            std::cout << "Materia already in inventory" << std::endl;
            return;
        }
        if (!_inventory[i])
        {
            _inventory[i] = m->clone();
            delete m;
            std::cout << getName() << " equiped " << _inventory[i]->getType() << " at " << i << std::endl;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3) {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    std::cout << getName() << " unequiped " << _inventory[idx]->getType() << " at slot" << idx << std::endl;
    delete _inventory[idx];
    for (; idx < 3; idx++)
    {
        _inventory[idx] = _inventory[idx + 1];
    }
    _inventory[3] = NULL;
}

void Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx > 3) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    if (_inventory[idx]) {
        if (_inventory[idx]) {
            _inventory[idx]->use(target);
        }
    }
}
