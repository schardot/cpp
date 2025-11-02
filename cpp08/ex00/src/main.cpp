#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
    // ===== VECTOR =====
    std::cout << "===== VECTOR =====" << std::endl;
    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 1);
        std::cout << "Found: " << *it << std::endl;
        it = easyfind(v, 4);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    // ===== LIST =====
    std::cout << "===== LIST =====" << std::endl;
    std::list<int> lst;
    lst.push_back(42);
    lst.push_back(21);
    lst.push_back(84);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 21);
        std::cout << "Found: " << *it << std::endl;
        it = easyfind(lst, 7);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    // ===== DEQUE =====
    std::cout << "===== DEQUE =====" << std::endl;
    std::deque<int> dq;
    dq.push_back(5);
    dq.push_back(10);
    dq.push_back(15);

    try
    {
        std::deque<int>::iterator it = easyfind(dq, 10);
        std::cout << "Found: " << *it << std::endl;
        it = easyfind(dq, 999);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    // ===== CONST CONTAINER TEST =====
    std::cout << "===== CONST VECTOR =====" << std::endl;
    std::vector<int> tmp;
    tmp.push_back(100);
    tmp.push_back(200);
    tmp.push_back(300);
    const std::vector<int> constV(tmp);
    try
    {
        std::vector<int>::const_iterator it = easyfind(constV, 200);
        std::cout << "Found: " << *it << std::endl;
        it = easyfind(constV, 400);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
