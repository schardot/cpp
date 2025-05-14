#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
    {
        std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
    }

void ClapTrap::attack(const std::string &target){
    std::cout << "ClapTrap " << this->_name << " is trying to attack!" << std::endl;
    if (_energyPoints == 0)
    {
        std::cout << "FAIL: ClapTrap " << this->_name
                  << " has no energy left to attack!" << std::endl;
        return;
    }
    if (_hitPoints == 0) {
        std::cout << "FAIL: ClapTrap " << this->_name
                  << " has no hit points left to attack!" << std::endl;
        return;
    }
    std::cout << "SUCCESS! ClapTrap " << this->_name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hitPoints -= amount;
    std::cout << "ClapTrap " << _name
              << " takes " << amount
              << " points of damage!" << std::endl;
    if (_hitPoints <= 0) {
        std::cout << "CAREFUL! ClapTrap " << _name
                  << " has 0 hit points!" << std::endl;
    }
    _energyPoints--;

}

void ClapTrap::beRepaired(unsigned int amount) {
    std::cout << "ClapTrap " << _name
              << " repaired itself with "
              << amount << " points!" << std::endl;
    _hitPoints += amount;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called for " << this->_name << std::endl;
};