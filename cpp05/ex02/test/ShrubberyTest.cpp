#include <iostream>
#include "../include/Colors.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main()
{

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 1: SCHRUBBERY CREATION FORM CONSTRUCTION & DESTRUCTION =====" << RESET << std::endl;
    {
        std::cout << std::endl;
        ShrubberyCreationForm form1("oi");
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 2: SCHRUBBERY CREATION FORM COPY CONSTRUCTOR =====" << RESET << std::endl;
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

    // std::cout << std::endl
    //           << RESET << BOLDYELLOW << "\n===== TEST 5: FUNCTIONALITY: FORM COPY ASSIGNMENT WITH DIFFERENT BOOLS =====" << RESET << std::endl;
    // {
    //     std::cout << std::endl;
    //     ShrubberyCreationForm form7;
    //     ShrubberyCreationForm aux;
    //     Bureaucrat b2;
    //     b2.signShrubberyCreationForm(form7);
    //     aux = form7;
    // }

    // std::cout << std::endl
    //           << RESET << BOLDYELLOW << "\n===== TEST 6: ERROR: TRYING TO SIGN A FORM WITH NOT ENOUGH GRADE =====" << RESET << std::endl;
    // {
    //     try
    //     {
    //         std::cout << std::endl;
    //         ShrubberyCreationForm form7("ShrubberyCreationForm 7", 100, 100);
    //         Bureaucrat b2("Bureaucrat 7", 140);
    //         b2.signShrubberyCreationForm(form7);
    //         std::cout << std::endl;
    //     }
    //     catch (std::exception &e)
    //     {
    //         std::cout << BOLDRED << "Caught exception: " << e.what() << RESET << std::endl;
    //     }
    // }

    return 0;
}
