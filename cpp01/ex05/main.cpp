#include "Harl.hpp"

int main(int ac, char **av) {
    Harl h;
    if (ac == 1)
        return (1);
    h.complain(av[1]);
}
