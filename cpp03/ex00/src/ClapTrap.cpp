#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default ClapTrap constructed!" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
    : _name(obj._name), _hitPoints(obj._hitPoints), _energyPoints(obj._energyPoints), _attackDamage(obj._attackDamage)
{
    std::cout << "ClapTrap " << _name << " copied from " << obj._name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
    std::cout << "ClapTrap " << _name << " called copy assignment operator to copy " << obj._name << std::endl;
    if (this != &obj) {
        _name = obj._name;
        _hitPoints = obj._hitPoints;
        _energyPoints = obj._energyPoints;
        _attackDamage = obj._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string &target){
    std::cout << "ClapTrap " << _name << " is trying to attack!" << std::endl;
    if (_energyPoints == 0)
    {
        std::cout << "FAIL: ClapTrap " << _name
                  << " has no energy left to attack!" << std::endl;
        return;
    }
    if (_hitPoints == 0) {
        std::cout << "FAIL: ClapTrap " << _name
                  << " has no hit points left to attack!" << std::endl;
        return;
    }
    std::cout << "SUCCESS! ClapTrap " << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= amount)
        _hitPoints = 0;
    else
        _hitPoints -= amount;
    std::cout << "ClapTrap " << _name
              << " takes " << amount
              << " points of damage!" << std::endl;
    if (_hitPoints == 0) {
        std::cout << "OH NO! ClapTrap " << _name
                  << " has 0 hit points!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints == 0) {
        std::cout << "FAIL: No energy to repair." << std::endl;
        return;
    }

    if (_hitPoints == 0) {
        std::cout << "FAIL: " << _name << " is dead and can't repair." << std::endl;
        return;
    }

    std::cout << "ClapTrap " << _name
              << " repaired itself with "
              << amount << " points!" << std::endl;
    _hitPoints += amount;
    _energyPoints--;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called for " << this->_name << std::endl;
};