#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <cctype>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &obj) { (void)obj; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
    (void)obj;
    return *this;
}

void ScalarConverter::convert(const std::string &arg) {

    enum Type { INVALID, CHAR, INT, FLOAT, DOUBLE, PSEUDO };
    Type type = INVALID;

    if (arg.length() < 0) {
        std::cout << "Invalid input: " << arg << std::endl;
        return;
    }

    if (isPseudo(arg))
        type = PSEUDO;
    else if (isChar(arg))
        type = CHAR;
    else if (isInt(arg))
        type = INT;
    else if (isFloat(arg))
        type = FLOAT;
    else if (isDouble(arg))
        type = DOUBLE;

    switch (type) {
        case PSEUDO: handlePseudo(arg); break;
        case CHAR: handleChar(arg); break;
        case INT: handleInt(arg); break;
        case FLOAT: handleFloat(arg); break;
        case DOUBLE: handleDouble(arg); break;
        default:
            std::cout << "Invalid input: " << arg << std::endl;
    }

}

bool ScalarConverter::isPseudo(const std::string &arg)
{
    const std::string pseudoDouble[] = {"nan", "inf", "+inf", "-inf"};
    const std::string pseudoFloat[] = {"nanf", "+inff", "-inff", "inff"};
    for (int i = 0; i < 4; i++) {
        if (arg == pseudoDouble[i] || arg == pseudoFloat[i])
            return (true);
    }
    return (false);
}

bool ScalarConverter::isChar(const std::string &arg)
{
    return (arg.length() == 1 && !std::isdigit(arg[0]));
}

bool ScalarConverter::isInt(const std::string &arg)
{
    int n = std::atoi(arg.c_str());

    if (arg != "0" && n == 0) {
        return false;
    }
    int len = arg.length();

    for (int i = 0; i < len; i ++) {
        if (i == 0 && (arg[0] == '+' || arg[0] == '-'))
            continue;
        if (!std::isdigit(arg[i]))
            return (false);
    }
    return (true);
}

bool ScalarConverter::isDouble(const std::string &arg)
{
    int len = arg.length();
    int point = 0;
    int i = 0;

    if  (arg[0] == '+' || arg[0] == '-')
        i = 1;

    if (arg[i] == '.')
        return (false);

    for (; i < len; i++)
    {
        if (arg[i] == '.')
        {
            if (point != 0)
                return (false);
            point++;
        }
        else if (arg[i] < '0' && arg[i] > '9') {
            return (false);
        }
    }

    //precisa desse outro?
    if (point != 1 || arg[len - 1] == '.' )
        return (false);
    return (true);
}

bool ScalarConverter::isFloat(const std::string &arg)
{
    int len = arg.length();
    if (len < 2 || arg[len - 1] != 'f')
        return false;

    std::string core = arg.substr(0, len - 1);
    return isDouble(core);
}

void ScalarConverter::handlePseudo(const std::string &arg) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::string dbl = arg;

    if (dbl == "nanf" || dbl == "+inff" || dbl == "-inff")
        dbl.erase(dbl.size() - 1);

    std::cout << "float: " << (arg.back() == 'f' ? arg : arg + "f") << std::endl;
    std::cout << "double: " << dbl << std::endl;
}

void ScalarConverter::handleChar(const std::string &arg) {
    char c = arg[0];

    if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    int n = static_cast<int>(c);
    float f = static_cast<float>(n);
    double d = static_cast<double>(n);

    std::cout << "int: " << n << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::handleInt(const std::string &arg) {
    int n = std::atoi(arg.c_str());

    if (arg != "0" && n == 0) {
        std::cout << "Invalid int" << std::endl;
        return;
    }

    std::cout << "char: ";
    if (n > 32 && n < 126)
        std::cout << "'" << static_cast<char>(n) << "'" << std::endl;
    else if (n >= 0 && n <= 255)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "impossible" << std::endl;
    std::cout << "int: " << n << std::endl;

    float f = static_cast<float>(n);
    double d = static_cast<double>(n);

    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::handleFloat(const std::string &arg) {
    float f = static_cast<float>(std::atof(arg.c_str()));
    char c = static_cast<char>(f);
    int n = static_cast<int>(f);
    double d = static_cast<double>(f);

    std::cout << "char: ";
    if ( f < 0 || f > 255) // f != f → NaN check
        std::cout << "impossible" << std::endl;
    else if (f >= 32 && f <= 126)
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: ";

    if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min() || f != f)
        std::cout << "impossible" << std::endl;
    else
        std::cout << n << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::handleDouble(const std::string &arg)
{
    double d = std::atof(arg.c_str());

    char c = static_cast<char>(d);
    int n = static_cast<int>(d);
    float f = static_cast<float>(d);

    // CHAR
    std::cout << "char: ";
    if (d < 0 || d > 255)
        std::cout << "impossible" << std::endl;
    else if (d >= 32 && d <= 126)
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    std::cout << "int: ";
    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "impossible" << std::endl;
    else
        std::cout << n << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}