#include "../include/ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &arg) {
    if (isPseudo(arg))
        ;
    else if (isChar(arg))
        handleChar(arg);
    else if (valid int literal)
        handle as int
    else if (valid float literal)
        handle as float
    else if (valid double literal)
        handle as double
    else
        invalid input

}

bool isPseudo(const std::string &arg) {
    const std::string pseudoDouble[] = {"nan", "inf", "+inf", "-inf"};
    const std::string pseudoFloat[] = {"nanf", "+inff", "-inff"};
    for (int i = 0; i < 5; i++) {
        if (arg == pseudoDouble[i])
            return (treatAsDouble);
    }

    for (int i = 0; i < 4; i++) {
        if (arg == pseudoFloat[i])
            return (treatAsFloat);
    }
    return (false);
}

bool isChar(const std::string &arg) {
    if (arg.length() > 1)
        return (false);
    if (arg[0] >= '0' && arg[0] <= '9')
        return (false);
    return (true);
}

bool isInt(const std::string &arg) {
    int len = arg.length();

    for (int i = 0; i < len; i ++) {
        if (i = 0 && (arg[0] == '+' || arg[0] == '-'))
            continue;
        if (!(arg[i] >= '0' && arg[i] <= '9'))
            return (false);
    }
    return (true);
}

bool isDouble(const std::string &arg)
{
    int len = arg.length();
    int point = 0;

    for (int i = 0; i < len; i++)
    {
        if (i = 0 && (arg[0] == '+' || arg[0] == '-'))
            continue;
        if (!(arg[i] >= '0' && arg[i] <= '9')) {
            if (arg[i] == '.')
                point ++;
            else
                return (false);
        }
    }
    if (point != 1 || (!(arg[len - 1] >= '0' && arg[len - 1] <= '9')))
        return (false);
    return (true);
}
