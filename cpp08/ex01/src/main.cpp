#include "Span.hpp"
#include <iostream>

int main() {

    std::cout << "=== Creating and trying to access empty Span ===" << std::endl;
    std::cout << "Span obj(0)" << std::endl;
    Span obje(0);
    try { obje.shortestSpan();
    } catch (std::exception &e) { std::cerr << e.what() << std::endl; }
    try { obje.longestSpan();
    } catch (std::exception &e) { std::cerr << e.what() << std::endl; }

    std::cout << "\n=== Creating and trying to add more than capacity ===" << std::endl;
    std::cout << "Span obj(4)" << std::endl;
    Span obj(4);
    try
    {
        obj.addNumber(3);
        obj.addNumber(4);
        obj.addNumber(7);
        obj.addNumber(40);
        obj.addNumber(14);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== Checking shortest and longest Span ===" << std::endl;
    std::cout << "Span obj: " << obj << std::endl;
    std::cout << "Shortest span: " << obj.shortestSpan() << ", longest span: " << obj.longestSpan() << std::endl;

    std::cout << "\n=== Adding a range at once ===" << std::endl;
    std::vector<int>range;
    for (int i = 0; i < 10000; i++) {
        range.push_back(i);
    }
    Span bigObj(10000);
    bigObj.addRange(range.begin(), range.end());
    std::cout << bigObj << std::endl;

    std::cout << "\n=== Adding a range larger than acceptable ===" << std::endl;
    std::vector<int> otherVector;
    for (int i = 0; i < 10; i++)
    {
        otherVector.push_back(i);
    }
    Span otherObj(9);
    try {
        otherObj.addRange(otherVector.begin(), otherVector.end());
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}