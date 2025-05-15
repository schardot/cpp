#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"), FragTrap(), ScavTrap()
{
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap default constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
    _name = name;
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << _name << " constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj), FragTrap(obj), ScavTrap(obj), _name(obj._name)
{
    std::cout << "DiamondTrap copied!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj) {
    if (this != &obj) {
        ClapTrap::operator=(obj);
        _name = obj._name;
    }
    std::cout << "DiamondTrap copy assignment operator called!" << std::endl;
    return *this;
}
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destructed!" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}