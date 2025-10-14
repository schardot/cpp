#include <iostream>
#include "../include/Colors.hpp"
#include "../include/RobotomyRequestForm.hpp"

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
        printTestLine("1", "FUNCTIONALITY –  ROBOTOMY REQUEST FORM CONSTRUCTION & DESTRUCTION");
    {
        std::cout << std::endl;
        RobotomyRequestForm form1("oi");
    }

    printTestLine("2", "FUNCTIONALITY –  ROBOTOMY REQUEST FORM COPY CONSTRUCTOR");
    {
        std::cout << std::endl;
        RobotomyRequestForm form2("oi");
        RobotomyRequestForm form2copy(form2);
    }


    printTestLine("3", "FUNCTIONALITY –  SUCESSFULLY SIGN A FORM");
    {
        std::cout << GRAY << "Quick info: In order to sign Robotomy Form, a Bureaucrat needs grade 72." << RESET << std::endl;
        std::cout << std::endl;
        RobotomyRequestForm form6("oi");
        Bureaucrat b1("Bureaucrat 6", 72);
        //b1.executeForm(form6); //Bureaucrat won't be able to execute
        b1.signForm(form6);
        std::cout << std::endl;
    }

    printTestLine("4", "FUNCTIONALITY –  SUCESSFULLY EXECUTE FORM");
    {
        std::cout << GRAY << "Quick info: In order to execute Robotomy Form, a Bureaucrat needs grade 45." << RESET << std::endl;
        RobotomyRequestForm form6("oi");
        Bureaucrat b1("Bureaucrat 6", 1);
        b1.signForm(form6);
        b1.executeForm(form6);
        std::cout << std::endl;
    }

    printTestLine("5", "ERROR –  TRYING TO EXECUTE FORM WITH NOT ENOUGH GRADE");
    {
        std::cout << GRAY << "Quick info: In order to execute Robotomy Form, a Bureaucrat needs grade 45." << RESET << std::endl;
        std::cout << std::endl;
        RobotomyRequestForm form6("oi");
        Bureaucrat b1("Bureaucrat 6", 71);
        b1.signForm(form6);
        b1.executeForm(form6);
        std::cout << std::endl;
    }

    printTestLine("6", "ERROR –  TRYING TO EXECUTE UNSIGNED FORM");
    {
        std::cout << std::endl;
        RobotomyRequestForm form6("oi");
        Bureaucrat b1("Bureaucrat 6", 144);
        //b1.signForm(form6);
        b1.executeForm(form6);
        std::cout << std::endl;
    }

    return 0;
}
