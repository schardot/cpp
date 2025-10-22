#include <iostream>
#include "Colors.hpp"
#include "Serializer.hpp"

static void printTestLine(std::string num, std::string message)
{
    std::cout << std::endl
              << RESET << BOLDYELLOW << "\n===== TEST "
              << num << ": "
              << message
              << " ===== " << RESET << std::endl;
}

int main()
{
    Data data;
    data.name = "42";
    data.value = 1337;
    printTestLine("1", "Original Data Pointer & content:");
    std::cout << "\n" << &data << std::endl;
    std::cout << "\nName: " << data.name << ", value: " << data.value << std::endl;

    printTestLine("2", "Serialized data (uintptr_t):");
    uintptr_t serialized = Serializer::serialize(&data);
    std::cout << "\n" << serialized << std::endl;

    printTestLine("3", "Deserialized Data pointer:");
    Data *deserialized = Serializer::deserialize(serialized);
    std::cout << "\n" << deserialized << std::endl;

    printTestLine("4", "Diff");
    if (deserialized == &data)
        std::cout << "\nSucess: pointers match" << std::endl;
    else
        std::cout << "\nError: pointers don't match" << std::endl;

    printTestLine("5", "Deserialized content");
    std::cout << "\nName: " << deserialized->name << ", value: " << deserialized->value << "\n" << std::endl;
}
