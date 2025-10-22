#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Colors.hpp"
#include "Functions.hpp"
#include <iostream>
#include <string>

static void printTestLine(std::string num, std::string message)
{
    std::cout << std::endl
              << RESET << BOLDYELLOW << "\n===== TEST "
              << num << ": "
              << message
              << " ===== " << RESET << std::endl;
}

int main () {

    printTestLine("1", "Identify from pointer");
    {
        Base *ptr = generate();
        std::cout << "Type generated: ";
        identify(ptr);
        delete ptr;
    }

    printTestLine("2", "Identify from reference");
    {
        Base *ptr = generate();
        std::cout << "Type generated: ";
        identify(*ptr);
        delete ptr;
    }
}