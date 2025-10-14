#include <iostream>
#include "../include/Colors.hpp"
#include "../include/Intern.hpp"

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
    printTestLine("1", "FUNCTIONALITY –  INTERN CREATION FORM CONSTRUCTION & DESTRUCTION");
    {
        std::cout << std::endl;
        Intern int1;
    }

    printTestLine("2", "FUNCTIONALITY –  INTERN FORM COPY CONSTRUCTOR");
    {
        std::cout << std::endl;
        Intern int2;
        Intern int2copy(int2);
    }

    printTestLine("3", "ERROR – FAIL TO CREATE A FORM DUE TO TYPO");
    {
        std::cout << std::endl;
        Intern int3;
        int3.makeForm("SHRUBBERY ceartion", "target");
        std::cout << std::endl;
    }

    printTestLine("4", "FUNCTIONALITY – SUCCESFULLY CREATE ALL FORMS");
    {
        std::cout << std::endl;
        Intern int3;
        AForm *f = int3.makeForm("shrubbery creation", "target");
        AForm *f1 = int3.makeForm("robotomy request", "target");
        AForm *f2 = int3.makeForm("presidential pardon", "target");

        delete f;
        delete f1;
        delete f2;
        std::cout << std::endl;
    }

    printTestLine("5", "FUNCTIONALITY – INTERN CREATE ALL FORMS, BUREAUCRAT SIGNS AND EXECUTE");
    {
        try
        {
            std::cout << std::endl;

            Bureaucrat bur1("Herr Bureaucrat", 1);
            std::cout << std::endl;

            Intern int3;
            std::cout << std::endl;

            AForm *f1 = int3.makeForm("shrubbery creation", "target");
            AForm *f2 = int3.makeForm("robotomy request", "target");
            AForm *f3 = int3.makeForm("presidential pardon", "target");
            std::cout << std::endl;

            bur1.signForm(*f1);
            bur1.executeForm(*f1);
            delete f1;
            std::cout << std::endl;

            bur1.signForm(*f2);
            bur1.executeForm(*f2);
            delete f2;
            std::cout << std::endl;

            bur1.signForm(*f3);
            bur1.executeForm(*f3);
            delete f3;
            std::cout << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << BOLDRED << "Caught exception during test 5: " << e.what() << RESET << std::endl;
        }
    }

    return 0;
}
