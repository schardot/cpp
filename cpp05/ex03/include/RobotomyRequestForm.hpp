#pragma once

#include "AForm.hpp"
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
private:
    std::string target_;
    virtual void execute(Bureaucrat const &executor) const;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &home);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &obj);

    RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
};
std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &obj);