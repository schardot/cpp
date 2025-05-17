#ifndef ICE_HPP
#define ICE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(std::string const &type);
    Ice(const Ice &obj);
    Ice &operator=(const Ice &obj);
    ~Ice();

    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);
};

#endif