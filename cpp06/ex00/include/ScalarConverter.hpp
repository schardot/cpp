#pragma once

#include <string>

class ScalarConverter
{
public:
    static void convert(const std::string &arg);

private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &obj);
    ScalarConverter &operator=(const ScalarConverter &obj);

    static bool isPseudo(const std::string &arg);
    static bool isChar(const std::string &arg);
    static bool isInt(const std::string &arg);
    static bool isFloat(const std::string &arg);
    static bool isDouble(const std::string &arg);

    static void handlePseudo(const std::string &arg);
    static void handleChar(const std::string &arg);
    static void handleInt(const std::string &arg);
    static void handleFloat(const std::string &arg);
    static void handleDouble(const std::string &arg);
};

