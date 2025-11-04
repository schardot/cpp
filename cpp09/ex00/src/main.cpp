#include <iostream>
#include <string>
#include "BitcoinExchange.hpp"


int main(int ac, char **av) {
    if (ac != 2)
        std::cerr << "Wrong usage" << std::endl;

    BitcoinExchange btc(av[1]);
}