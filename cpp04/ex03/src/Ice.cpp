#include "../include/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    _type = "ice";
    std::cout << "Default Ice constructed!" << std::endl;
}

Ice::Ice(const Ice &obj) : AMateria(obj)
{
    //_type = obj._type; // pay attention, something about deep copy
    std::cout << "Ice copied" << std::endl;
}

Ice &Ice::operator=(const Ice &obj)
{
    if (this != &obj)
    {
        AMateria::operator=(obj);
        std::cout << "Copy assignment called for Ice!" << std::endl;
    }
    return *this;
}

Ice::~Ice()
{
    std::cout << "Ice destructed!" << std::endl;
}

AMateria *Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " * " << std::endl;
}