#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "\n===== TEST 1: MAX HIT POINT DAMAGE =====" << std::endl;
    ClapTrap robot("Taia");
    robot.attack("Newton");
    robot.takeDamage(10);   // Should reduce HP to 0
    robot.attack("Newton"); // Should fail due to 0 HP
    robot.attack("Newton"); // Should still fail
    robot.beRepaired(5);    // Should fail due to 0 HP
    robot.takeDamage(5);    // Should stay at 0 HP
    robot.beRepaired(10);   // Still should fail
    std::cout << "==== END TEST 1 ====\n"
              << std::endl;

    std::cout << "===== TEST 2: ATTACK UNTIL NO ENERGY =====" << std::endl;
    ClapTrap bot("Elmira");
    for (int i = 0; i < 10; i++)
    {
        bot.attack("Manuel"); // Should succeed for 10 attacks
    }
    bot.attack("Manuel"); // Should fail (0 energy)
    bot.beRepaired(10);    // Should fail (0 energy)
    bot.takeDamage(5);    // Should still work (no energy needed)
    std::cout << "==== END TEST 2 ====\n"
              << std::endl;

    std::cout << "===== TEST 3: REPAIR LOGIC (WHILE ALIVE) =====" << std::endl;
    ClapTrap c3("Leona");
    c3.takeDamage(9);
    c3.beRepaired(10); // Should succeed
    c3.attack("Zed"); // Should still succeed
    std::cout << "==== END TEST 3 ====\n"
              << std::endl;

    std::cout << "===== TEST 4: REPAIR LOGIC (WHILE DEAD) =====" << std::endl;
    ClapTrap c4("Tania");
    c4.takeDamage(10);
    c4.beRepaired(10); // Should fail
    c4.attack("Dasha"); // Should fail
    std::cout << "==== END TEST 3 ====\n"
              << std::endl;


    return 0;
}
