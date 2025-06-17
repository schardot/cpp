#include <iostream>
#include "../include/Colors.hpp"
#include "../include/Bureaucrat.hpp"

int main()
{
    std::cout << RESET << BOLDYELLOW << "\n===== TEST 1: DEFAULT BUREAUCRAT CONSTRUCTION & DESTRUCTION =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        Bureaucrat a1;
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 2: NAMED BUREAUCRAT CONSTRUCTION & DESTRUCTION =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        Bureaucrat a1("A1", 100);
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 3: BUREAUCRAT COPY CONSTRUCTOR =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        Bureaucrat a2("A2", 50);
        std::cout << MAGENTA;
        Bureaucrat a2copy(a2);
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 4: BUREAUCRAT COPY ASSIGNMENT =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        Bureaucrat a3("A3", 20);
        Bureaucrat a4("A4", 10);
        std::cout << BLUE;
        a3 = a4;
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 5: FUNCTIONALITY: OPERATOR << OVERLOAD =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        Bureaucrat a5("A5", 5);
        std::cout << PURPLE << a5;
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 6: FUNCIONALITY: INCREMENT AND DECREMENT GRADE =====" << RESET << std::endl;
    {
        std::cout << CYAN;
        Bureaucrat a6("A6", 100);
        std::cout << BOLDGREEN;
        a6.incrementGrade();
        std::cout << BOLDYELLOW;
        a6.decrementGrade();
        std::cout << DIM << GRAY;
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 7: HIGH EXCEPTION: INITIALIZING WITH ABOVE MAXIMUM GRADE (0) =====" << RESET << std::endl;
    {
        try
        {
            std::cout << BRIGHT_CYAN;
            Bureaucrat a7("A7", 0);
            std::cout << DIM << GRAY;
        }
        catch (std::exception &e)
        {
            std::cout << BOLDRED << "Caught exception: " << e.what() << RESET << std::endl;
        }
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 8: HIGH EXCEPTION: DECREMENTING HIGHEST GRADE =====" << RESET << std::endl;
    {
        try
        {
            std::cout << BRIGHT_BLUE;
            Bureaucrat a8("A8", 1);
            a8.decrementGrade();
            std::cout << DIM << GRAY;
        }
        catch (std::exception &e)
        {
            std::cout << BOLDRED << "Caught exception: " << e.what() << RESET << std::endl;
        }
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 9: LOW EXCEPTION: INITIALIZING WITH BELOW MINUMUM GRADE (151) =====" << RESET << std::endl;
    {
        try
        {
            std::cout << BRIGHT_MAGENTA;
            Bureaucrat a9("A9", 151);
            std::cout << DIM << GRAY;
        }
        catch (std::exception &e)
        {
            std::cout << BOLDRED << "Caught exception: " << e.what() << RESET << std::endl;
        }
    }

    std::cout << RESET << BOLDYELLOW << "\n===== TEST 10: LOW EXCEPTION: INCREMENTING MINIMUM GRADE =====" << RESET << std::endl;
    {
        try
        {
            std::cout << BRIGHT_GREEN;
            Bureaucrat a10("A10", 150);
            a10.incrementGrade();
            std::cout << DIM << GRAY;
        }
        catch (std::exception &e)
        {
            std::cout << BOLDRED << "Caught exception: " << e.what() << RESET << std::endl;
        }
    }

    std::cout << RESET << std::endl;
    return 0;
}
