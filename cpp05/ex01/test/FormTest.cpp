#include <iostream>
#include "../include/Colors.hpp"
#include "../include/Form.hpp"

int main()
{

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 1: FUNCTIONALITY: NAMED FORM CONSTRUCTION & DESTRUCTION =====" << RESET << std::endl;
    {
        std::cout << std::endl;
        Form form1("Form 1", 20, 50);
    }

    std::cout << std::endl << RESET << BOLDYELLOW << "\n===== TEST 2: FUNCTIONALITY: FORM COPY CONSTRUCTOR =====" << RESET << std::endl;
    {
        std::cout << std::endl;
        Form form2("Form 2", 10, 2);
        Form form2copy(form2);
    }

    std::cout << std::endl << RESET << BOLDYELLOW << "\n===== TEST 3: FUNCTIONALITY: OPERATOR << OVERLOAD =====" << RESET << std::endl;
    {
        std::cout << std::endl;
        Form form5("Form 5", 5, 5);
        std::cout << form5;
        std::cout << std::endl;
    }

    std::cout << std::endl << RESET << BOLDYELLOW << "\n===== TEST 4: FUNCTIONALITY: SUCESSFULLY SIGN A FORM WITH EXACT GRADE =====" << RESET << std::endl;
    {
        std::cout << std::endl;
        Form form6("Form 6", 100, 100);
        Bureaucrat b1("Bureaucrat 6", 100);
        b1.signForm(form6);
        std::cout << std::endl;
    }

    std::cout << std::endl << RESET << BOLDYELLOW << "\n===== TEST 5: FUNCTIONALITY: FORM COPY ASSIGNMENT WITH DIFFERENT BOOLS =====" << RESET << std::endl;
    {
        std::cout << std::endl;
        Form form7("Form 7", 100, 100);
        Form aux("Aux Form", 50, 50);
        Bureaucrat b2("Bureaucrat 7", 100);
        b2.signForm(form7);
        aux = form7;
    }

    std::cout << std::endl << RESET << BOLDYELLOW << "\n===== TEST 6: ERROR: TRYING TO SIGN A FORM WITH NOT ENOUGH GRADE =====" << RESET << std::endl;
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

    return 0;
}
