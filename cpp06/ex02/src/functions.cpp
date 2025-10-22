#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

void identify(Base *p) {
    if (dynamic_cast<A*>(p)) //will return a nullptr if incorrect
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

Base *generate(void)
{
    std::srand(static_cast<unsigned int> (time(NULL)));
    Base *ret;

    int n = std::rand() % 3;
    switch (n)
    {
    case 0:
        ret = new A;
        break;
    case 1:
        ret = new B;
        break;
    default:
        ret = new C;
        break;
    }

    return ret;
}

void identify(Base &p) {
    //now the dynamic is different since dynamic_cast won't return a nullptr, instead throw an exception. so using if else is not possible anymore
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (...) {}

    std::cout << "Unknown type" << std::endl;
}