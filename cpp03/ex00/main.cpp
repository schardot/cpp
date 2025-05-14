#include "ClapTrap.hpp"

int main(void) {
    ClapTrap robot = ClapTrap("Taia");
    ClapTrap bot = ClapTrap("Elmira");

    std::cout << "\n--- TEST 1: MAX HIT POINT DAMAGE ---" << std::endl;
    robot.attack("Newton");
    robot.takeDamage(10);
    robot.attack("Newton");
    robot.attack("Newton");
    robot.beRepaired(10);
    robot.attack("Newton");

    std::cout << "\n--- TEST 2: ATTACK 10x TIL NO ENERGY LEFT---" << std::endl;
    for (int i = 0; i < 11; i++) {
        bot.attack("Manuel");
    }
    std::cout << "\n";
}