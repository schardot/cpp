#include "../include/Dog.hpp"
#include "../include/Colors.hpp"

int main(void)
{
    std::cout << BOLDYELLOW << "\n===== TEST 1: DOG CONSTRUCTION & DESTRUCTION =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        Dog a1;
        std::cout << GRAY << "Type is: " << GREEN << a1.getType() << std::endl;
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 2: DOG COPY CONSTRUCTOR =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        Dog a2;
        std::cout << GRAY << "Type is: " << GREEN << a2.getType() << std::endl;
        std::cout << MAGENTA;
        Dog a2copy(a2);
        std::cout << GRAY << "Type is: " << GREEN << a2.getType() << std::endl;
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 3: DOG COPY ASSIGNMENT =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        Dog a3;
        Dog a4;
        std::cout << BLUE;
        a3 = a4;
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << std::endl;
    return 0;
}
