#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
    std::string _type;
public:
    AMateria();
    AMateria(std::string const &type);
    AMateria(const AMateria &obj);
    AMateria &operator=(const AMateria &obj);
    virtual ~AMateria();

    std::string const &getType() const;

    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif