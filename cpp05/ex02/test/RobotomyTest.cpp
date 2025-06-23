#include <iostream>
#include "../include/Colors.hpp"
#include "../include/RobotomyRequestForm.hpp"

int main()
{

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 1: ROBOTOMY REQUEST FORM CONSTRUCTION & DESTRUCTION =====" << RESET << std::endl;
    {
        std::cout << std::endl;
        RobotomyRequestForm form1("oi");
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 2: ROBOTOMY REQUEST FORM COPY CONSTRUCTOR =====" << RESET << std::endl;
    {
        std::cout << std::endl;
        RobotomyRequestForm form2("oi");
        RobotomyRequestForm form2copy(form2);
    }


    std::cout << RESET << BOLDYELLOW << "\n===== TEST 3: FUNCTIONALITY: SUCESSFULLY SIGN A FORM =====" << RESET << std::endl;
    {
        std::cout << GRAY << "Quick info: In order to sign Robotomy Form, a Bureaucrat needs grade 72." << RESET << std::endl;
        std::cout << std::endl;
        RobotomyRequestForm form6("oi");
        Bureaucrat b1("Bureaucrat 6", 145);
        b1.signForm(form6);
        std::cout << std::endl;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 4: FUNCTIONALITY: SUCESSFULLY EXECUTE ROBOTOMY =====" << RESET << std::endl;
    {
        std::cout << GRAY << "Quick info: In order to execute Robotomy Form, a Bureaucrat needs grade 45." << RESET << std::endl;
        RobotomyRequestForm form6("oi");
        Bureaucrat b1("Bureaucrat 6", 1);
        b1.signForm(form6);
        b1.executeForm(form6);
        std::cout << std::endl;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 5: ERROR: TRYING TO EXECUTE ROBOTOMY WITH NOT ENOUGH GRADE =====" << RESET << std::endl;
    {
        std::cout << GRAY << "Quick info: In order to execute Robotomy Form, a Bureaucrat needs grade 45." << RESET << std::endl;
        std::cout << std::endl;
        RobotomyRequestForm form6("oi");
        Bureaucrat b1("Bureaucrat 6", 71);
        b1.signForm(form6);
        b1.executeForm(form6);
        std::cout << std::endl;
    }

    return 0;
}
