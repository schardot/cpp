#include "../include/MateriaSource.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/Colors.hpp" // Optional, for colorful output

#include <iostream>

int main()
{
    std::cout << GREEN << "\n===== TEST: MateriaSource learn and create =====\n" << RESET;

    IMateriaSource *src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\nTrying to create Ice Materia..." << std::endl;
    AMateria *ice = src->createMateria("ice");
    if (ice)
        std::cout << "Created Materia of type: " << ice->getType() << std::endl;
    else
        std::cout << "Failed to create Ice Materia!" << std::endl;

    std::cout << "\nTrying to create Cure Materia..." << std::endl;
    AMateria *cure = src->createMateria("cure");
    if (cure)
        std::cout << "Created Materia of type: " << cure->getType() << std::endl;
    else
        std::cout << "Failed to create Cure Materia!" << std::endl;

    std::cout << "\nTrying to create Unknown Materia..." << std::endl;
    AMateria *unknown = src->createMateria("fire");
    if (!unknown)
        std::cout << "Correctly failed to create unknown Materia." << std::endl;

    std::cout << BOLDGREEN << "\n===== CLEANUP =====\n"
              << RESET;

    delete ice;
    delete cure;
    delete unknown;
    delete src;

    return 0;
}
