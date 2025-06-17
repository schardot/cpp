#pragma once

#include <string>
#include <iostream>

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