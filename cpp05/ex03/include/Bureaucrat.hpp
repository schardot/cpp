#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "Colors.hpp"

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

    static void validateGrade(int grade);

public:
    Bureaucrat();
    Bureaucrat(std:: string name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &obj);

    Bureaucrat &operator=(const Bureaucrat &obj);

    const std::string &getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
    void signForm(AForm &obj);
    void executeForm(AForm const & form);

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);