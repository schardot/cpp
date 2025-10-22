#include "../include/ScalarConverter.hpp"
#include <iostream>

int main(void)
{
    std::cout << "===== CHAR TESTS =====" << std::endl;
    ScalarConverter::convert("a");
    ScalarConverter::convert("z");
    ScalarConverter::convert("~");

    std::cout << "\n===== INT TESTS =====" << std::endl;
    ScalarConverter::convert("0");
    ScalarConverter::convert("42");
    ScalarConverter::convert("-42");
    ScalarConverter::convert("2147483647");  // INT_MAX
    ScalarConverter::convert("-2147483648"); // INT_MIN

    std::cout << "\n===== FLOAT TESTS =====" << std::endl;
    ScalarConverter::convert("0.0f");
    ScalarConverter::convert("42.0f");
    ScalarConverter::convert("-42.42f");
    ScalarConverter::convert("3.14159f");
    ScalarConverter::convert("nanf");
    ScalarConverter::convert("+inff");
    ScalarConverter::convert("-inff");

    std::cout << "\n===== DOUBLE TESTS =====" << std::endl;
    ScalarConverter::convert("0.0");
    ScalarConverter::convert("42.42");
    ScalarConverter::convert("-42.4242");
    ScalarConverter::convert("3.14159");
    ScalarConverter::convert("nan");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("-inf");

    std::cout << "\n===== INVALID TESTS =====" << std::endl;
    ScalarConverter::convert("abc");
    ScalarConverter::convert("12f3");
    ScalarConverter::convert("--42");
    ScalarConverter::convert("4.2.1");
    ScalarConverter::convert("f42");
    ScalarConverter::convert("");

    return 0;
}
