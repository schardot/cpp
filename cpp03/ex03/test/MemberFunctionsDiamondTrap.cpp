#include "../include/DiamondTrap.hpp"
#include "../include/Colors.hpp"

int main(void)
{

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 1: WHO AM I FUNCTION =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        DiamondTrap d2("Echo");
        std::cout << GREEN;
        d2.whoAmI();
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 2: ATTACK FROM SCAV INHERITANCE =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        DiamondTrap d3("Falcon");
        std::cout << ATTACK_COLOR;
        d3.attack("enemy");
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 3: TAKE DAMAGE AND REPAIR (CLAP FUNCTIONS) =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        DiamondTrap d4("Ghost");
        std::cout << DAMAGE_COLOR;
        d4.takeDamage(30);
        std::cout << REPAIR_COLOR;
        d4.beRepaired(20);
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 4: MULTIPLE ACTIONS =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        DiamondTrap d5("Halo");
        std::cout << ATTACK_COLOR;
        d5.attack("target1");
        std::cout << DAMAGE_COLOR;
        d5.takeDamage(50);
        std::cout << REPAIR_COLOR;
        d5.beRepaired(10);
        std::cout << GREEN;
        d5.whoAmI();
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << std::endl;
    return 0;
}
