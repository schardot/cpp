#include <iostream>
#include "../include/Colors.hpp"
#include "../include/PresidentialPardonForm.hpp"

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
    printTestLine("1", "FUNCTIONALITY –  PRESIDENTIAL PARDON CREATION FORM CONSTRUCTION & DESTRUCTION");
    {
        std::cout << std::endl;
        PresidentialPardonForm form1("oi");
    }

    printTestLine("2", "FUNCTIONALITY –  PRESIDENTIAL PARDON FORM COPY CONSTRUCTOR");
    {
        std::cout << std::endl;
        PresidentialPardonForm form2("oi");
        PresidentialPardonForm form2copy(form2);
    }

    printTestLine("3", "FUNCTIONALITY –  SUCESSFULLY SIGN A FORM");
    {
        std::cout << GRAY << "Quick info: In order to sign Presidential Form, a Bureaucrat needs grade 25." << RESET << std::endl;
        std::cout << std::endl;
        PresidentialPardonForm form6("oi");
        Bureaucrat b1("Bureaucrat 1", 25);
        b1.signForm(form6);
        // b1.executeForm(form6); //Bureaucrat won't be able to execute
        std::cout << std::endl;
    }

    printTestLine("4", "FUNCTIONALITY –  SUCESSFULLY EXECUTE FORM");
    {
        std::cout << GRAY << "Quick info: In order to execute Presidential Form, a Bureaucrat needs grade 5." << RESET << std::endl;
        PresidentialPardonForm form6("oi");
        Bureaucrat b1("Bureaucrat 2", 5);
        b1.signForm(form6);
        b1.executeForm(form6);
        std::cout << std::endl;
    }

    printTestLine("5", "ERROR –  TRYING TO EXECUTE FORM WITH NOT ENOUGH GRADE");
    {
        std::cout << GRAY << "Quick info: In order to execute Presidential Form, a Bureaucrat needs grade 5." << RESET << std::endl;
        std::cout << std::endl;
        PresidentialPardonForm form6("oi");
        Bureaucrat b1("Bureaucrat 3", 6);
        b1.signForm(form6);
        b1.executeForm(form6);
        std::cout << std::endl;
    }

    printTestLine("6", "ERROR –  TRYING TO EXECUTE UNSIGNED FORM");
    {
        std::cout << std::endl;
        PresidentialPardonForm form6("oi");
        Bureaucrat b1("Bureaucrat 6", 3);
        // b1.signForm(form6);
        b1.executeForm(form6);
        std::cout << std::endl;
    }

    return 0;
}
