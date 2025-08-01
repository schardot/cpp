#include "../include/Animal.hpp"
#include "../include/Colors.hpp"

int main(void)
{
    std::cout << BOLDYELLOW << "\n===== TEST 1: ANIMAL CONSTRUCTION & DESTRUCTION =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        Animal a1;
        std::cout << GRAY << "Type is: " << GREEN << a1.getType() << std::endl;
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 2: ANIMAL COPY CONSTRUCTOR =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        Animal a2;
        std::cout << MAGENTA;
        Animal a2copy(a2);
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 3: ANIMAL COPY ASSIGNMENT =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        Animal a3;
        Animal a4;
        std::cout << BLUE;
        a3 = a4;
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << std::endl;
    return 0;
}
