#include "Fixed.hpp"

Fixed::Fixed() : rawBits (0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) {
    std::cout << "Copy constructor called" << std::endl;
    rawBits = obj.getRawBits();
}

Fixed& Fixed::operator = (const Fixed &obj) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
        rawBits = obj.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (rawBits);
}

void Fixed::setRawBits(int const raw) {
    rawBits = raw;
}