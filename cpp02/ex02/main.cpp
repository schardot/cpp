#include <iostream>
#include "Fixed.hpp"

int main()
{
    std::cout << "=== Constructors ===" << std::endl;
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);
    Fixed e;
    e = c;

    std::cout << "\na = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;

    std::cout << "\n=== Comparison Operators ===" << std::endl;
    std::cout << "b > c: " << (b > c) << std::endl;
    std::cout << "b < c: " << (b < c) << std::endl;
    std::cout << "b >= d: " << (b >= d) << std::endl;
    std::cout << "b <= d: " << (b <= d) << std::endl;
    std::cout << "b == d: " << (b == d) << std::endl;
    std::cout << "b != c: " << (b != c) << std::endl;

    std::cout << "\n=== Arithmetic Operators ===" << std::endl;
    Fixed f = c + b;
    Fixed g = c - b;
    Fixed h = c * Fixed(2);
    Fixed i = c / Fixed(2);

    std::cout << "c + b = " << f << std::endl;
    std::cout << "c - b = " << g << std::endl;
    std::cout << "c * 2 = " << h << std::endl;
    std::cout << "c / 2 = " << i << std::endl;

    std::cout << "\n=== Increment / Decrement ===" << std::endl;
    Fixed inc;
    std::cout << "Start: " << inc << std::endl;
    std::cout << "Pre-increment: " << ++inc << std::endl;
    std::cout << "After pre-increment: " << inc << std::endl;
    std::cout << "Post-increment: " << inc++ << std::endl;
    std::cout << "After post-increment: " << inc << std::endl;

    std::cout << "Pre-decrement: " << --inc << std::endl;
    std::cout << "After pre-decrement: " << inc << std::endl;
    std::cout << "Post-decrement: " << inc-- << std::endl;
    std::cout << "After post-decrement: " << inc << std::endl;

    std::cout << "\n=== Min / Max ===" << std::endl;
    Fixed x(3.14f);
    Fixed y(5.5f);
    const Fixed cx(7.7f);
    const Fixed cy(1.1f);

    std::cout << "Min(x, y): " << Fixed::min(x, y) << std::endl;
    std::cout << "Max(x, y): " << Fixed::max(x, y) << std::endl;
    std::cout << "Min(cx, cy): " << Fixed::min(cx, cy) << std::endl;
    std::cout << "Max(cx, cy): " << Fixed::max(cx, cy) << std::endl;

    return 0;
}
