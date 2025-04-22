#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie *zb = newZombie(name);
    zb->announce();
    return delete zb;
}