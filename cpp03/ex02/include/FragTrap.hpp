#ifndef FragTRAP_HPP
#define FragTRAP_HPP

#include "ClapTrap.hpp"
#include "iostream"
#include <string>

class FragTrap : public ClapTrap {
public:
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &obj);
    FragTrap &operator=(const FragTrap &obj);
    ~FragTrap();

    void highFivesGuys(void);
};

#endif
