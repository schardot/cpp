#include "ScavTrap.hpp"
#include "Colors.hpp"

int main(void)
{
    std::cout << RESET << BOLDYELLOW << "\n===== TEST 1: SCAVTRAP CONSTRUCTION =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        ScavTrap s1("Ana");
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 2: GUARD KEEPER MODE =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        ScavTrap s2("Bob");
        std::cout << PURPLE;
        s2.guardGate();
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 3: SCAV ATTACK MODE =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        ScavTrap s3("Clint");
        std::cout << ATTACK_COLOR;
        s3.attack("Fly");
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 4: TESTING THE 100 HITPOINT =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        ScavTrap s4("David");
        std::cout << DAMAGE_COLOR;
        s4.takeDamage(99);
        s4.takeDamage(1);
        std::cout << ATTACK_COLOR;
        s4.attack("Donnie");
        std::cout << DIM << GRAY;
    }
    std::cout << RESET << std::endl;
    return 0;
}
