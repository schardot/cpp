#include <iostream>
#include "../include/Colors.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main()
{
    std::cout << RESET << BOLDYELLOW << "\n===== TEST 1: PRESIDENTIAL PARDON FORM CONSTRUCTION & DESTRUCTION =====" << RESET << std::endl;
    {
        std::cout << std::endl;
        PresidentialPardonForm form1("oi");
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 2: PRESIDENTIAL PARDON FORM COPY CONSTRUCTOR =====" << RESET << std::endl;
    {
        std::cout << std::endl;
        PresidentialPardonForm form2("oi");
        PresidentialPardonForm form2copy(form2);
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 3: FUNCTIONALITY: SUCESSFULLY SIGN A FORM =====" << RESET << std::endl;
    {
        std::cout << GRAY << "Quick info: In order to sign Presidential Form, a Bureaucrat needs grade 25." << RESET << std::endl;
        std::cout << std::endl;
        PresidentialPardonForm form6("oi");
        Bureaucrat b1("Bureaucrat 1", 5);
        b1.signForm(form6);
        std::cout << std::endl;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 4: FUNCTIONALITY: SUCESSFULLY EXECUTE PARDON =====" << RESET << std::endl;
    {
        std::cout << GRAY << "Quick info: In order to execute Presidential Form, a Bureaucrat needs grade 5." << RESET << std::endl;
        PresidentialPardonForm form6("oi");
        Bureaucrat b1("Bureaucrat 2", 5);
        b1.signForm(form6);
        b1.executeForm(form6);
        std::cout << std::endl;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 5: ERROR: TRYING TO EXECUTE ROBOTOMY WITH NOT ENOUGH GRADE =====" << RESET << std::endl;
    {
        std::cout << GRAY << "Quick info: In order to execute Presidential Form, a Bureaucrat needs grade 5." << RESET << std::endl;
        std::cout << std::endl;
        PresidentialPardonForm form6("oi");
        Bureaucrat b1("Bureaucrat 3", 6);
        b1.signForm(form6);
        b1.executeForm(form6);
        std::cout << std::endl;
    }

    return 0;
}
