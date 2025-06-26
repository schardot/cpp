#include <iostream>
#include "../include/Colors.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main()
{

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 1: SHRUBBERY CREATION FORM CONSTRUCTION & DESTRUCTION =====" << RESET << std::endl;
    {
        std::cout << std::endl;
        ShrubberyCreationForm form1("oi");
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 2: SHRUBBERY CREATION FORM COPY CONSTRUCTOR =====" << RESET << std::endl;
    {
        std::cout << std::endl;
        ShrubberyCreationForm form2("oi");
        ShrubberyCreationForm form2copy(form2);
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 3: FUNCTIONALITY: SUCESSFULLY SIGN A FORM =====" << RESET << std::endl;
    {
        std::cout << GRAY << "Quick info: In order to sign Shrubbery Form, a Bureaucrat needs grade 145." << RESET << std::endl;
        std::cout << std::endl;
        ShrubberyCreationForm form6("oi");
        Bureaucrat b1("Bureaucrat 6", 145);
        b1.signForm(form6);
        std::cout << std::endl;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 4: FUNCTIONALITY: SUCESSFULLY EXECUTE SHRUBBERY =====" << RESET << std::endl;
    {
        std::cout << GRAY << "Quick info: In order to execute Shrubbery Form, a Bureaucrat needs grade 137." << RESET << std::endl;
        ShrubberyCreationForm form6("oi");
        Bureaucrat b1("Bureaucrat 6", 137);
        b1.signForm(form6);
        b1.executeForm(form6);
        std::cout << std::endl;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 5: ERROR: TRYING TO EXECUTE SHRUBBERY WITH NOT ENOUGH GRADE =====" << RESET << std::endl;
    {
        std::cout << GRAY << "Quick info: In order to execute Shrubbery Form, a Bureaucrat needs grade 137." << RESET << std::endl;
        std::cout << std::endl;
        ShrubberyCreationForm form6("oi");
        Bureaucrat b1("Bureaucrat 6", 144);
        b1.signForm(form6);
        b1.executeForm(form6);
        std::cout << std::endl;
    }

    return 0;
}
