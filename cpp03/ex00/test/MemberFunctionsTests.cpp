#include "../include/ClapTrap.hpp"
#include "../include/Colors.hpp"

int main(void)
{
    std::cout << RESET << BOLDYELLOW << "\n===== TEST 1: MAX HIT POINT DAMAGE =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        ClapTrap robot("1");
        std::cout << ATTACK_COLOR;
        robot.attack("Bob");
        std::cout << DAMAGE_COLOR;
        robot.takeDamage(10);
        std::cout << ATTACK_COLOR;
        robot.attack("Newton");
        robot.attack("Newton");
        std::cout << REPAIR_COLOR;
        robot.beRepaired(5);
        std::cout << DAMAGE_COLOR;
        robot.takeDamage(5);
        std::cout << REPAIR_COLOR;
        robot.beRepaired(10);
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 2: ATTACK UNTIL NO ENERGY =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        ClapTrap bot("Elmira");
        std::cout << ATTACK_COLOR;
        for (int i = 0; i < 10; i++)
        {
            std::cout << i << " ";
            bot.attack("Manuel");
        }
        bot.attack("Manuel");
        std::cout << REPAIR_COLOR;
        bot.beRepaired(10);
        std::cout << DAMAGE_COLOR;
        bot.takeDamage(5);
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 3: REPAIR LOGIC (WHILE ALIVE) =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        ClapTrap c3("Tania");
        std::cout << DAMAGE_COLOR;
        c3.takeDamage(9);
        std::cout << REPAIR_COLOR;
        c3.beRepaired(10);
        std::cout << ATTACK_COLOR;
        c3.attack("Zed");
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 4: REPAIR LOGIC (WHILE DEAD) =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        ClapTrap c4("Dasha");
        std::cout << DAMAGE_COLOR;
        c4.takeDamage(10);
        std::cout << REPAIR_COLOR;
        c4.beRepaired(10);
        std::cout << ATTACK_COLOR;
        c4.attack("the attack will fail anyway!");
        std::cout << DIM << GRAY;
    }
    std::cout << RESET << std::endl;
    return 0;
}
