#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "../include/Form.hpp"

class Form;

class Bureaucrat
{
private:
    const std::string name;
    int grade;

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
    void signForm(Form &obj);


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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);