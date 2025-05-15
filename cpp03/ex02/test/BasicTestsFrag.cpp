#include "../include/FragTrap.hpp"
#include "../include/Colors.hpp"

int main(void)
{
    std::cout << BOLDYELLOW << "\n===== TEST 1: FragTRAP CONSTRUCTION & DESTRUCTION =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        FragTrap c1("1");
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 2: FragTRAP SHALLOW COPY =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        FragTrap c2("2");
        std::cout << MAGENTA;
        FragTrap c2a(c2);
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 3: FragTRAP COPY ASSIGNMENT =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        FragTrap c3("3");
        FragTrap c4("4");
        std::cout << BLUE;
        c3 = c4;
        std::cout << DIM << GRAY;
    }
    std::cout << RESET << std::endl;
    return 0;
}
