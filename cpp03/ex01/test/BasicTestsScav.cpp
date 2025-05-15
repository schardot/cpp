#include "../include/ScavTrap.hpp"
#include "../include/Colors.hpp"

int main(void)
{
    std::cout << BOLDYELLOW << "\n===== TEST 1: SCAVTRAP CONSTRUCTION & DESTRUCTION =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        ScavTrap c1("1");
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 2: SCAVTRAP SHALLOW COPY =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        ScavTrap c2("2");
        std::cout << MAGENTA;
        ScavTrap c2a(c2);
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 3: SCAVTRAP COPY ASSIGNMENT =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        ScavTrap c3("3");
        ScavTrap c4("4");
        std::cout << BLUE;
        c3 = c4;
        std::cout << DIM << GRAY;
    }
    std::cout << RESET << std::endl;
    return 0;
}
