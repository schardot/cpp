#include "Harl.hpp"

int main(int ac, char **av) {
    Harl h;
    if (ac != 2)
        return (1);
    h.complain(av[1]);
}
