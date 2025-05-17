#include <iostream>
#include "../include/AAnimal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/Brain.hpp"
#include "../include/Colors.hpp"

int main()
{
    const int size = 6; // even number
    AAnimal *animals[size];

    std::cout << BOLDYELLOW << "\n===== TEST: Creating AAnimals array =====" << RESET << std::endl;
    for (int i = 0; i < size / 2; ++i)
        animals[i] = new Dog();

    for (int i = size / 2; i < size; ++i)
        animals[i] = new Cat();

    std::cout << BOLDYELLOW << "\n===== TEST: AAnimals makeSound() =====" << RESET << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << CYAN << i << ": ";
        animals[i]->makeSound();
    }

    std::cout << BOLDYELLOW << "\n===== TEST: Deep copy for Dog =====" << RESET << std::endl;
    Dog *originalDog = new Dog();
    originalDog->getBrain()->setIdea(0, "Original dog idea");

    Dog *copiedDog = new Dog(*originalDog);
    std::cout << MAGENTA << "Copied dog's first idea: " << copiedDog->getBrain()->getIdea(0) << RESET << std::endl;

    copiedDog->getBrain()->setIdea(0, "Changed copied dog idea");
    std::cout << GREEN << "Original dog's first idea after copy changed: " << originalDog->getBrain()->getIdea(0) << RESET << std::endl;

    delete originalDog;
    delete copiedDog;

    std::cout << BOLDYELLOW << "\n===== TEST: Deep copy for Cat =====" << RESET << std::endl;
    Cat *originalCat = new Cat();
    originalCat->getBrain()->setIdea(0, "Original cat idea");

    Cat *copiedCat = new Cat(*originalCat);
    std::cout << MAGENTA << "Copied cat's first idea: " << copiedCat->getBrain()->getIdea(0) << RESET << std::endl;

    copiedCat->getBrain()->setIdea(0, "Changed copied cat idea");
    std::cout << GREEN << "Original cat's first idea after copy changed: " << originalCat->getBrain()->getIdea(0) << RESET << std::endl;

    delete originalCat;
    delete copiedCat;

    std::cout << BOLDYELLOW << "\n===== TEST: Deleting AAnimals array =====" << RESET << std::endl;
    for (int i = 0; i < size; ++i)
        delete animals[i];

    return 0;
}