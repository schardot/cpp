#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Colors.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string name_;
    bool isSigned_;
    const int MinSignGrade_;
    const int MinExecGrade_;

    static void validateGrade(int grade);

public:
    Form();
    Form(const std::string &name, int MinSignGrade, int MinExecGrade);
    ~Form();
    Form(const Form &obj);
    Form &operator=(const Form &obj);

    const std::string &getName() const { return (name_); }
    const bool &getIsSigned() const { return (isSigned_); }
    const int &getMinSignGrade() const { return (MinSignGrade_); }
    const int &getMinExecGrade() const { return (MinExecGrade_); }

    bool beSigned(const Bureaucrat &b);

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

std::ostream &operator<<(std::ostream &out, const Form &obj);
