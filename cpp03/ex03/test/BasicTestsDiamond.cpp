#include "../include/DiamondTrap.hpp"
#include "../include/Colors.hpp"

int main(void)
{
    std::cout << BOLDYELLOW << "\n===== TEST 1: DiamondTrap CONSTRUCTION & DESTRUCTION =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        DiamondTrap c1("1");
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 2: DiamondTrap SHALLOW COPY =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        DiamondTrap c2("2");
        std::cout << MAGENTA;
        DiamondTrap c2a(c2);
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 3: DiamondTrap COPY ASSIGNMENT =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        DiamondTrap c3("3");
        DiamondTrap c4("4");
        std::cout << BLUE;
        c3 = c4;
        std::cout << DIM << GRAY;
    }
    std::cout << RESET << std::endl;
    return 0;
}
