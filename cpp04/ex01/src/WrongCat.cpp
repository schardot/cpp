#include "../include/WrongCat.hpp"

WrongCat::WrongCat()
{
    _type = "WrongCat";
    std::cout << "Default WrongCat constructed!" << std::endl;
};

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
    std::cout << "WrongCat copied!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
    if (this != &obj)
    {
        WrongAnimal::operator=(obj);
    }
    std::cout << "WrongCat copied using copy assignment!" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called!" << std::endl;
};

void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound: Does it even matter?" << std::endl;
}
