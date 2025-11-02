#include "MutantStack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);  // Stack: [5]
    mstack.push(17); // Stack: [17, 5]
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();    // removes 17
    std::cout << "Size: " << mstack.size() << std::endl;
    mstack.push(3); // Stack: [3, 5]
    mstack.push(5); // Stack: [5, 3, 5]
    mstack.push(737); // Stack: [737, 5, 3, 5]
    mstack.push(0);   // Stack: [0, 737, 5, 3, 5]

    MutantStack<int>::IT it = mstack.begin(); //begin is the oldest element, bottom of the stack! so 5
    MutantStack<int>::IT ite = mstack.end();  // begin is the newest element, top of the stack! so 0

    while (it != ite)
    {
        std::cout << *ite << std::endl;
        ++it;
    }

    std::stack<int> s(mstack); //the fact that it compiles is already a check :)
    return 0;
}
