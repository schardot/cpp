#include "RPN.hpp"
#include <iostream>
#include <string>

int main (int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Wrong usage" << std::endl;
        return 1;
    }
    std::string s(av[1]);
    RPN obj(s);
}