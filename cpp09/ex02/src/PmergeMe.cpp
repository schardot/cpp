#include "PmergeMe.hpp"
#include <cstdlib>
#include <cstring>
#include <exception>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <ctime>

PmergeMe::PmergeMe(int ac, char **av): vecComparisons(0), deqComparisons(0)
{
    if (ac < 2)
        throw std::runtime_error("Error");
    for (int i = 1; i < ac; ++i)
    {
        std::istringstream iss(av[i]);
        int num;
        iss >> num;
        if (iss.fail() || !iss.eof() || num < 0)
            throw std::runtime_error("Error");
        vec.push_back(num);
        deq.push_back(num);
    }
    run();
}

void PmergeMe::run() {
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << ' ';
    std::cout << std::endl;

    clock_t vecStart = std::clock();
    std::vector<Node> vecNodes = buildNodeVector(vec);
    vecNodes = fordJohnsonVec(vecNodes);
    clock_t vecEnd = std::clock();

    clock_t deqStart = std::clock();
    std::deque<Node> deqNodes = buildNodeDeque(deq);
    deqNodes = fordJohnsonDeq(deqNodes);
    clock_t deqEnd = std::clock();

    std::cout << "After: ";
    for (size_t i = 0; i < vecNodes.size(); i++)
        std::cout << vecNodes[i].val << ' ';
    std::cout << std::endl;

    double vecUs = (static_cast<double>(vecEnd - vecStart) * 1000000.0) / CLOCKS_PER_SEC;
    double deqUs = (static_cast<double>(deqEnd - deqStart) * 1000000.0) / CLOCKS_PER_SEC;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << vecUs << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque : " << deqUs << " us" << std::endl;
    size_t optimal = optimalComparisons(vec.size());
    std::cout << "Comparisons with std::vector: " << vecComparisons
              << " (optimal <= " << optimal << ")" << std::endl;
    std::cout << "Comparisons with std::deque: " << deqComparisons
              << " (optimal <= " << optimal << ")" << std::endl;
}

