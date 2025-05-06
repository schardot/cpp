#include "Harl.hpp"

int main(int ac, char **av) {
    Harl h;
    if (ac != 2)
    {
        std::cout << "Usage: ./harlFilter <log_level>" << std::endl;
        return 1;
    }
    h.findLevel(av[1]);
}
