#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num){
    rawBits = num << fractionalBits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
{
    rawBits = roundf(num * (1 << fractionalBits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) : rawBits(obj.rawBits) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed &obj) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj) {
        rawBits =  obj.rawBits;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return rawBits;
}

void Fixed::setRawBits(int const raw) { rawBits = raw; }

float Fixed::toFloat(void) const {  return ((float)rawBits / (1 << fractionalBits)); }

int Fixed::toInt(void) const {  return (rawBits >> fractionalBits); }

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    out << value.toFloat();
    return out;
}
