#include <iostream>
#include "../include/Colors.hpp"
#include "../include/Intern.hpp"

int main()
{

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 1: INTERN CREATION FORM CONSTRUCTION & DESTRUCTION =====" << RESET << std::endl;
    {
        std::cout << std::endl;
        Intern int1;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 2: INTERN CREATION FORM COPY CONSTRUCTOR =====" << RESET << std::endl;
    {
        std::cout << std::endl;
        Intern int2;
        Intern int2copy(int2);
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 3: ERROR: FAIL TO CREATE A FORM DUE TO TYPO =====" << RESET << std::endl;
    {
        std::cout << std::endl;
        Intern int3;
        int3.makeForm("SHRUBBERY ceartion", "target");
        std::cout << std::endl;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 4: FUNCTIONALITY: SUCCESFULLY CREATE ALL FORMS =====" << RESET << std::endl;
    {
        std::cout << std::endl;
        Intern int3;
        int3.makeForm("shrubbery creation", "target");
        int3.makeForm("robotomy request", "target");
        int3.makeForm("presidential pardon", "target");
        std::cout << std::endl;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 5: INTERN CREATE SHRUBBERY FORM, BUREAUCRAT SIGNS AND EXECUTE =====" << RESET << std::endl;
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
        std::cout << std::endl;

        bur1.signForm(*f2);
        bur1.executeForm(*f2);
        std::cout << std::endl;

        bur1.signForm(*f3);
        bur1.executeForm(*f3);
        std::cout << std::endl;

        std::cout << std::endl;
    }

    return 0;
}
