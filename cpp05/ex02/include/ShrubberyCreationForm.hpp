#pragma once

#include "AForm.hpp"
#include <string>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    std::string target_;
    virtual void execute(Bureaucrat const &executor) const;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &home);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &obj);

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
};
