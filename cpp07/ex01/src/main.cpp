#include "../include/iter.hpp"
#include <string>

int main()
{
    std::cout << "Printing ints:" << std::endl;
    int myNum[3] = {72, 101, 121};
    //print(myNum[0]); //example to show type deduction
    iter(myNum, 3, print<int>);
    iter(myNum, 3, increment<int>);
    iter(myNum, 3, print<char>);
    std::cout << std::endl;

    std::cout << "Printing const ints:" << std::endl;
    const int constNum[3] = {11, 22, 33};
    iter(constNum, 3, print<const int>);
    //iter(constNum, 3, increment<int>); //example when using print(T element)
    //iter(constNum, 3, print<int>);
    std::cout << std::endl;

    std::cout << "Printing chars:" << std::endl;
    char charNum[3] = {'H', 'e', 'y'};
    iter(charNum, 3, print<char>);
    std::cout << std::endl;

    std::cout << "Printing doubles:" << std::endl;
    double doubleNum[3] = {3.4, 4.5, 5.6};
    iter(doubleNum, 3, print<double>);
    std::cout << std::endl;

    std::cout << "Printing const strings:" << std::endl;
    const std::string stringAr[3] = {"hello", "there", ":)"};
    iter(stringAr, 3, print<const std::string>);
    std::cout << std::endl;
}