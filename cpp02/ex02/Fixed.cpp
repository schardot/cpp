#include "Fixed.hpp"

Fixed::Fixed()
{
    rawBits = 0;
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

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed& Fixed::operator = (const Fixed &obj) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj) {
        this->rawBits =  obj.rawBits;
    }
    return (*this);
}

bool Fixed::operator< (const Fixed &obj) const {
    return (rawBits < obj.rawBits);
}

bool Fixed::operator> (const Fixed &obj) const {
    return (rawBits > obj.rawBits);
}

bool Fixed::operator<=(const Fixed &obj) const {
    return (rawBits <= obj.rawBits);
}

bool Fixed::operator>=(const Fixed &obj) const {
    return (rawBits >= obj.rawBits);
}

bool Fixed::operator==(const Fixed &obj) const {
    return (rawBits == obj.rawBits);
}

bool Fixed::operator!=(const Fixed &obj) const {
    return (rawBits != obj.rawBits);
}

Fixed Fixed::operator+(const Fixed &obj) const {

    return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed Fixed::operator-(const Fixed &obj) const {

    return (Fixed(this->toFloat() - obj.toFloat()));
}

Fixed Fixed::operator*(const Fixed &obj) const {

    return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed Fixed::operator/(const Fixed &obj) const {

    return (Fixed(this->toFloat() / obj.toFloat()));
}

Fixed& Fixed::operator++() {
    rawBits++;
    return *this;
}

Fixed &Fixed::operator--() {
    rawBits--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    rawBits++;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    rawBits--;
    return temp;
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

float Fixed::toFloat(void) const {
    return ((float)rawBits / 256);
}

int Fixed::toInt(void) const {
    return (rawBits >> fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
    out << value.toFloat();
    return out;
}

Fixed &Fixed::min(Fixed &one, Fixed &two) {
    if (one > two)
        return two;
    return one;
}

const Fixed &Fixed::min(const Fixed &one, const Fixed &two) {
    if (one > two)
        return two;
    return one;
}

Fixed &Fixed::max(Fixed &one, Fixed &two) {
    if (one < two)
        return two;
    return one;
}

const Fixed &Fixed::max(const Fixed &one, const Fixed &two) {
    if (one < two)
        return two;
    return one;
}
