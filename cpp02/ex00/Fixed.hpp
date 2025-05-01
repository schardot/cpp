#include <iostream>

class Fixed
{
private:
    int fixedPointNumberValue;
    static const int numOfFractionalBits = 8;
public:
    Fixed();
    Fixed(const Fixed &obj);
    ~Fixed();
    Fixed &operator = (const Fixed &obj);

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

