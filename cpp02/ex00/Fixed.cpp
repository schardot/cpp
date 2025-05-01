#include "Fixed.hpp"

Fixed::Fixed()
{
    fixedPointNumberValue = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) {
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPointNumberValue = obj.getRawBits();
}

Fixed& Fixed::operator = (const Fixed &obj) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixedPointNumberValue = obj.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (fixedPointNumberValue);
}

void Fixed::setRawBits(int const raw) {
    fixedPointNumberValue = raw;
}