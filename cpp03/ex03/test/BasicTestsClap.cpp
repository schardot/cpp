#include "../include/ClapTrap.hpp"
#include "../include/Colors.hpp"

int main(void)
{
    std::cout << BOLDYELLOW << "\n===== TEST 1: CLAPTRAP CONSTRUCTION & DESTRUCTION =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        ClapTrap c1("1");
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 2: CLAPTRAP SHALLOW COPY =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        ClapTrap c2("2");
        std::cout << MAGENTA;
        ClapTrap c2a(c2);
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 3: CLAPTRAP COPY ASSIGNMENT=====" << RESET << std::endl;
    {
        std::cout << CYAN;
        ClapTrap c3("3");
        ClapTrap c4("4");
        std::cout << BLUE;
        c3 = c4;
        std::cout << DIM << GRAY;
    }
    std::cout << RESET << std::endl;
    return 0;
}
