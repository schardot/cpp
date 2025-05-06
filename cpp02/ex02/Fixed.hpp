#include <iostream>
#include <cmath>

class Fixed
{
private:
    int fixedPointNumberValue;
    static const int numOfFractionalBits = 8;
public:
    Fixed();
    Fixed(const int num);
    Fixed(const float num);
    Fixed(const Fixed &obj);
    ~Fixed();
    Fixed &operator = (const Fixed &obj);
    bool operator > (const Fixed &obj);
    bool operator < (const Fixed &obj);
    bool operator >= (const Fixed &obj);
    bool operator <= (const Fixed &obj);
    bool operator == (const Fixed &obj);
    bool operator != (const Fixed &obj);
    Fixed operator + (const Fixed &obj);
    Fixed operator - (const Fixed &obj);
    Fixed operator * (const Fixed &obj);
    Fixed operator / (const Fixed &obj);
    Fixed &operator ++ ();
    Fixed operator ++ (int);
    Fixed &operator -- ();

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);
