#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
private:
    AForm *createShrubberyForm(std::string const &target);
    AForm *createPresidentialForm(std::string const &target);
    AForm *createRobotomyForm(std::string const &target);

public:
    Intern();
    Intern(const Intern &obj);
    ~Intern();
    Intern &operator=(const Intern &obj);

    AForm *makeForm(const std::string &formName, const std::string &target);
};
