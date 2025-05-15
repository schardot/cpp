#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor called!" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj) {
    std::cout << "ScavTrap " << _name << " copied!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj) {
    if (this != &obj) {
        ClapTrap::operator=(obj);
    }
    std::cout << "ScavTrap " << _name << " assigned to " << obj._name << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " destructed!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " now in Gate Keeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    //std::cout << "SCAV..... ScavTrap " << _name << " is trying to attack!" << std::endl;
    if (_energyPoints == 0)
    {
        std::cout << "FAIL: ScavTrap " << _name
                  << " has no energy left to attack!" << std::endl;
        return;
    }
    if (_hitPoints == 0)
    {
        std::cout << "FAIL: ScavTrap " << _name
                  << " has no hit points left to attack!" << std::endl;
        return;
    }
    std::cout << "SCAV..... SUCCESS! ScavTrap " << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
    _energyPoints--;
}