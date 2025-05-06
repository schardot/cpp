#include <iostream>

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

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);
