#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>
#include <iostream>

class Character : public ICharacter
{
private:
    AMateria *_inventory[4];
    std::string _name;
public:
    Character();
    Character(std::string const &name);
    Character(const Character &obj);
    Character &operator=(const Character &obj);
    ~Character();

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif