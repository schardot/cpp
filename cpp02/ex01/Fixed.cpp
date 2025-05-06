#include "Fixed.hpp"

Fixed::Fixed()
{
    fixedPointNumberValue = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num){
    this->setRawBits(8);
    fixedPointNumberValue = num << numOfFractionalBits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
{
    this->setRawBits(8);
    fixedPointNumberValue = num * 256;
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPointNumberValue = obj.numOfFractionalBits;
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

float Fixed::toFloat(void) const {
    return (fixedPointNumberValue / 256);
}


int Fixed::toInt(void) const {
    return (fixedPointNumberValue >> 8);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    out << value.toFloat();
    return out;
}
