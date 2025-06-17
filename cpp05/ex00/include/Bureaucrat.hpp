#pragma once

#include <string>
#include <iostream>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

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

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);
