#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "iostream"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string _name;
public:
    DiamondTrap();
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &obj);
    DiamondTrap &operator=(const DiamondTrap&obj);
    ~DiamondTrap();

    void whoAmI();
    void attack(const std::string &target);
};

#endif