#include "../include/Character.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include <iostream>

int main()
{
    std::cout << "\033[1;32m===== TEST: Character equip/use/unequip & deep copy =====\033[0m\n";

    Character alice("Taia");
    Character bob("Bob");

    Ice *ice = new Ice();
    Cure *cure = new Cure();

    std::cout << "\n\033[1;34m-- Taia equips Ice and Cure --\033[0m\n";
    alice.equip(ice);
    alice.equip(cure);

    std::cout << "\n\033[1;34m-- Taia uses Materias on Bob --\033[0m\n";
    alice.use(0, bob);
    alice.use(1, bob);

    std::cout << "\n\033[1;34m-- Taia unequips Materia at index 1 --\033[0m\n";
    alice.unequip(1);

    std::cout << "\n\033[1;34m-- Taia tries to use unequipped slot --\033[0m\n";
    alice.use(1, bob);

    std::cout << "\n\033[1;34m-- Deep copy Taia to Charlie --\033[0m\n";
    Character charlie = alice;

    std::cout << "\n\033[1;34m-- Charlie uses Materia at index 0 on Bob --\033[0m\n";
    charlie.use(0, bob);

    std::cout << "\n\033[1;34m-- Clean up dynamically allocated Materias --\033[0m\n";

    return 0;
}
