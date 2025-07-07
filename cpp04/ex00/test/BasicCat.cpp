#include "../include/Cat.hpp"
#include "../include/Colors.hpp"

int main(void)
{
    std::cout << BOLDYELLOW << "\n===== TEST 1: CAT CONSTRUCTION & DESTRUCTION =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        Cat a1;
        std::cout << GRAY << "Type is: " << GREEN << a1.getType() << std::endl;
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 2: CAT COPY CONSTRUCTOR =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        Cat a2;
        std::cout << GRAY << "Type is: " << GREEN << a2.getType() << std::endl;

        std::cout << MAGENTA;
        Cat a2copy(a2);
        std::cout << GRAY << "Type is: " << GREEN << a2.getType() << std::endl;

        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 3: CAT COPY ASSIGNMENT =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        Cat a3;
        Cat a4;
        std::cout << BLUE;
        a3 = a4;
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << std::endl;
    return 0;
}
