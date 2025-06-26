#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Colors.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool _isSigned;
    const int _MinSignGrade;
    const int _MinExecGrade;

    static void validateGrade(int grade);

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

    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

protected:
    virtual void validateExecutionRequirements(Bureaucrat const & executor) const;

public:
    AForm();
    AForm(const std::string &name, int MinSignGrade, int MinExecGrade);
    virtual ~AForm();
    AForm(const AForm &obj);
    AForm &operator=(const AForm &obj);

    const std::string &getName() const;
    const bool &getIsSigned() const;
    const int &getMinSignGrade() const;
    const int &getMinExecGrade() const;

    bool beSigned(const Bureaucrat &b);
    virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);
