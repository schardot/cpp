#include "../include/AAnimal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Colors.hpp"

int main(void)
{
    std::cout << BOLDYELLOW << "\n===== TEST: MEMBER FUNCTIONS AND INHERITANCE =====" << RESET << std::endl;

    //const AAnimal *animal = new AAnimal();
    const AAnimal *cat = new Cat();
    const AAnimal *dog = new Dog();

    std::cout << CYAN << "\n--- TYPES ---" << RESET << std::endl;
    //std::cout << "animal->getType(): " << animal->getType() << std::endl;
    std::cout << "cat->getType(): " << cat->getType() << std::endl;
    std::cout << "dog->getType(): " << dog->getType() << std::endl;

    std::cout << MAGENTA << "\n--- SOUNDS ---" << RESET << std::endl;
    // std::cout << "animal->makeSound(): ";
    // animal->makeSound();
    std::cout << "cat->makeSound(): ";
    cat->makeSound();
    std::cout << "dog->makeSound(): ";
    dog->makeSound();

    std::cout << DIM << GRAY << "\n--- DELETING ---" << RESET << std::endl;
    // delete animal;
    delete cat;
    delete dog;

    std::cout << RESET << std::endl;

    std::cout << BOLDYELLOW << "\n===== TEST: WRONG ANIMAL HIERARCHY =====" << RESET << std::endl;

    const WrongAnimal *wrongAAnimal = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();

    std::cout << CYAN << "\n--- TYPES ---" << RESET << std::endl;
    std::cout << "wrongAAnimal->getType(): " << wrongAAnimal->getType() << std::endl;
    std::cout << "wrongCat->getType(): " << wrongCat->getType() << std::endl;

    std::cout << MAGENTA << "\n--- SOUNDS ---" << RESET << std::endl;
    std::cout << "wrongAAnimal->makeSound(): ";
    wrongAAnimal->makeSound();
    std::cout << "wrongCat->makeSound(): ";
    wrongCat->makeSound();

    std::cout << DIM << GRAY << "\n--- DELETING WRONG ANIMALS ---" << RESET << std::endl;
    delete wrongAAnimal;
    delete wrongCat;

    std::cout << RESET << std::endl;

    return 0;
}
