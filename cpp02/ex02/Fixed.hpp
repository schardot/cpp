#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int rawBits;
    static const int fractionalBits = 8;
public:
    Fixed();
    Fixed(const int num);
    Fixed(const float num);
    Fixed(const Fixed &obj);
    ~Fixed();
    Fixed &operator = (const Fixed &obj);
    bool operator>(const Fixed &obj) const;
    bool operator<(const Fixed &obj) const;
    bool operator>=(const Fixed &obj) const;
    bool operator<=(const Fixed &obj) const;
    bool operator==(const Fixed &obj) const;
    bool operator!=(const Fixed &obj) const;
    Fixed operator+(const Fixed &obj) const;
    Fixed operator-(const Fixed &obj) const;
    Fixed operator*(const Fixed &obj) const;
    Fixed operator/(const Fixed &obj) const;
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    static Fixed &min(Fixed &one, Fixed &two);
    static const Fixed &min(const Fixed &one, const Fixed &two);
    static Fixed &max(Fixed &one, Fixed &two);
    static const Fixed &max(const Fixed &one, const Fixed &two);
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif