#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include "iostream"

class ClapTrap
{
private:
    std::string _name;
    unsigned int _hitPoints;
    int _energyPoints;
    unsigned int _attackDamage;
public:
    ClapTrap(); //do i need it
    ClapTrap(const std::string &name);
    ~ClapTrap();

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif