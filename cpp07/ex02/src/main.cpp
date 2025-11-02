#include "Array.hpp"
#include "Array.tpp"
#include <string>
#include <iostream>

int main()
{
    unsigned int len = 3;
    std::cout << "Int array:" << std::endl;
    Array<int> intArray(len);
    for (unsigned int  i = 0; i < len; i++) {
        intArray[i] = i;
    }
    std::cout << intArray;
    // std::cout << "\n* Now modyfing first element of array to 42 *" << std::endl;
    // intArray[0] = 42;
    // std::cout << "New modified array: " << intArray << std::endl;

    // std::cout << "\n* Now copying array *" << std::endl;
    // Array<int> copyArray(intArray);
    // std::cout << "New copied array: " << copyArray << std::endl;

    // std::cout << "\n* Now assigning array *" << std::endl;
    // Array<int> newIntArray(len);
    // for (unsigned int i = 0; i < len; i++)
    // {
    //     newIntArray[i] = i + 99;
    // }
    // std::cout << "New array: " << newIntArray << " vs. old array: " << intArray << std::endl;
    // newIntArray = intArray;
    // std::cout << "Now new = old: " << newIntArray << " vs. old array: " << intArray << std::endl;

    // -------------- CHAR ARRAY ----------------
    // std::cout << "Testing other types of arrays:" << std::endl;
    // std::cout << "Char array:" << std::endl;
    // Array<char> charArray(len);
    // for (unsigned int i = 0; i < len; i++)
    // {
    //     charArray[i] = i + 35;
    // }
    // std::cout << charArray;

    // std::cout << "Empty string array:" << std::endl;
    // Array<std::string> strArray;
    // std::cout << strArray;

    // std::cout << "\n* Now trying to acess empty string *" << std::endl;
    // try {
    //     strArray[1];
    // } catch (std::exception &e) {
    //     std::cerr << e.what() << std::endl;
    //}

    //-------------- CONST ------------------
    // const Array<int> constInt(len);
    // std::cout << "Const int array: " << constInt;
    // std::cout << "Now checking array[0]: " << constInt[0] << std::endl;

    // const Array<int> newConstInt(intArray);
    // std::cout << "New const constructed by copy of intArray " << newConstInt;
}