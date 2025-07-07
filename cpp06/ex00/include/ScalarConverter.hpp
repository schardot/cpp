#pragma once

#include <string>

class ScalarConverter
{
private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &obj);
    ScalarConverter &operator =(const ScalarConverter &obj);

public:
    void convert (std::string arg);
};

