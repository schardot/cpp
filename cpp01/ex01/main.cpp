#include "Zombie.hpp"

int main(void) {
    std::string name = "Pedro";
    int num = 2;

    Zombie *horde = zombieHorde(num, name);
    for (int i = 0; i < num; i++) {
        horde[i].announce();
    }
    delete[] horde;
}