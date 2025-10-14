#pragma once

#include "AForm.hpp"
#include <string>
#include <fstream>

class PresidentialPardonForm : public AForm
{
private:
    std::string target_;
    virtual void execute(Bureaucrat const &executor) const;

public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &home);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &obj);

    PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
};
