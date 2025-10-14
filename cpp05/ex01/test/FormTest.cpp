#include <iostream>
#include "../include/Colors.hpp"
#include "../include/Form.hpp"

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

    printTestLine("1", "FUNCTIONALITY –  NAMED FORM CONSTRUCTION & DESTRUCTION");
    {
        std::cout << std::endl;
        Form form1("Form 1", 20, 50);
    }

    printTestLine("2", "FUNCTIONALITY – FORM COPY CONSTRUCTOR");
    {
        std::cout << std::endl;
        Form form2("Form 2", 10, 2);
        Form form2copy(form2);
    }

    printTestLine("3", "FUNCTIONALITY – OPERATOR << OVERLOAD");
    {
        std::cout << std::endl;
        Form form5("Form 5", 5, 5);
        std::cout << form5;
        std::cout << std::endl;
    }

    printTestLine("4", "FUNCTIONALITY – SUCESSFULLY SIGN A FORM WITH EXACT GRADE");
    {
        std::cout << std::endl;
        Form form6("Form 6", 100, 100);
        Bureaucrat b1("Bureaucrat 6", 100);
        b1.signForm(form6);
        std::cout << std::endl;
    }

    printTestLine("5", "FUNCTIONALITY – FORM COPY ASSIGNMENT WITH DIFFERENT BOOLS");
    {
        std::cout << std::endl;
        Form form7("Form 7", 100, 100);
        Form aux("Aux Form", 50, 50);
        Bureaucrat b2("Bureaucrat 7", 100);
        b2.signForm(form7);
        aux = form7;
    }

    printTestLine("6", "ERROR – TRYING TO SIGN A FORM WITH NOT ENOUGH GRADE");
    {
        try
        {
            std::cout << std::endl;
            Form form7("Form 7", 100, 100);
            Bureaucrat b2("Bureaucrat 7", 140);
            b2.signForm(form7);
            std::cout << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << BOLDRED << "Caught exception: " << e.what() << RESET << std::endl;
        }
    }

    printTestLine("7", "ERROR – SIGNING AN ALREADY SIGNED FORM");
    {
        Form f("DoubleSign", 100, 100);
        Bureaucrat b("Signer", 50);

        b.signForm(f);
        b.signForm(f);
    }

    printTestLine("8", "ERROR – FORM CREATION WITH INVALID GRADES");
    {
        try
        {
            Form f1("InvalidHigh", 0, 10);
        }
        catch (std::exception &e)
        {
            std::cout << BOLDRED << "Caught exception: " << e.what() << RESET << std::endl;
        }

        try
        {
            Form f2("InvalidLow", 100, 151);
        }
        catch (std::exception &e)
        {
            std::cout << BOLDRED << "Caught exception: " << e.what() << RESET << std::endl;
        }
    }

    std::cout << RESET << std::endl;
    return 0;
}
