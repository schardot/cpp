#include "ClapTrap.hpp"

#define RESET "\033[0m"
#define DIM "\033[2m"
#define BOLDYELLOW "\033[1;33m"
#define CYAN "\033[36m"
#define GRAY "\033[2;37m"
#define MAGENTA "\033[35m"
#define BLUE "\033[34m"

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
