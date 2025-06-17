#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Colors.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool isSigned;
    const int MinSignGrade;
    const int MinExecGrade;

    static void validateGrade(int grade);

public:
    Form();
    Form(const std::string &name, int MinSignGrade, int MinExecGrade);
    ~Form();
    Form(const Form &obj);
    Form &operator=(const Form &obj);

    const std::string &getName() const;
    const bool &getIsSigned() const;
    const int &getMinSignGrade() const;
    const int &getMinExecGrade() const;

    bool beSigned(const Bureaucrat &b);

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const _NOEXCEPT;
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const _NOEXCEPT;
    };
};

std::ostream &operator<<(std::ostream &out, const Form &obj);
