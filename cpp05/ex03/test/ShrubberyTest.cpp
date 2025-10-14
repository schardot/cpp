#include <iostream>
#include "../include/Colors.hpp"
#include "../include/ShrubberyCreationForm.hpp"

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

    printTestLine("1", "FUNCTIONALITY –  SHRUBBERY CREATION FORM CONSTRUCTION & DESTRUCTION");
    {
        std::cout << std::endl;
        ShrubberyCreationForm form1("oi");
    }

    printTestLine("2", "FUNCTIONALITY –  SHRUBBERY CREATION FORM COPY CONSTRUCTOR");
    {
        std::cout << std::endl;
        ShrubberyCreationForm form2("oi");
        ShrubberyCreationForm form2copy(form2);
    }

    printTestLine("3", "FUNCTIONALITY –  SUCESSFULLY SIGN A FORM");
    {
        std::cout << GRAY << "Quick info: In order to sign Shrubbery Form, a Bureaucrat needs grade 145." << RESET << std::endl;
        std::cout << std::endl;
        ShrubberyCreationForm form6("oi");
        Bureaucrat b1("Bureaucrat 6", 145);
        b1.signForm(form6);
        //b1.executeForm(form6); //Bureaucrat won't be able to execute
        std::cout << std::endl;
    }

    printTestLine("4", "FUNCTIONALITY –  SUCESSFULLY EXECUTE FORM");
    {
        std::cout << GRAY << "Quick info: In order to execute Shrubbery Form, a Bureaucrat needs grade 137." << RESET << std::endl;
        ShrubberyCreationForm form6("oi");
        Bureaucrat b1("Bureaucrat 6", 137);
        b1.signForm(form6);
        b1.executeForm(form6);
        std::cout << std::endl;
    }

    printTestLine("5", "ERROR –  TRYING TO EXECUTE FORM WITH NOT ENOUGH GRADE");
    {
        std::cout << GRAY << "Quick info: In order to execute Shrubbery Form, a Bureaucrat needs grade 137." << RESET << std::endl;
        std::cout << std::endl;
        ShrubberyCreationForm form6("oi");
        Bureaucrat b1("Bureaucrat 6", 144);
        b1.signForm(form6);
        b1.executeForm(form6);
        std::cout << std::endl;
    }

    printTestLine("6", "ERROR –  TRYING TO EXECUTE UNSIGNED FORM");
    {
        std::cout << std::endl;
        ShrubberyCreationForm form6("oi");
        Bureaucrat b1("Bureaucrat 6", 144);
        //b1.signForm(form6);
        b1.executeForm(form6);
        std::cout << std::endl;
    }

    return 0;
}
