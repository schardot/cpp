#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av)
{
    try {
        PmergeMe(ac, av);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}