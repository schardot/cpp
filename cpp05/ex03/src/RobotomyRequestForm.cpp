#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target_(target) {
    std::cout << BOLDGREEN << "RobotomyRequestForm constructed! " << std::endl << RESET;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << DIM << GRAY << "RobotomyRequestForm destructed. " << std::endl << RESET;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj), target_(obj.target_) {
    std::cout << CYAN << "Copy!" << RESET << " New " << obj.getName() << " created." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
    if (this != &obj) {
        AForm::operator=(obj);
        target_ = obj.target_;
        std::cout << MAGENTA << "Copy assignment operator called!" << RESET << std::endl;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    validateExecutionRequirements(executor);
    std::cout << "* Drilling noises *" << std::endl;
    std::srand(std::time(NULL));
    if (std::rand() % 2)
    {
        std::cout << target_ << " has been robotomized successfully." << std::endl;
    }
    else
    {
        std::cout << "The robotomy failed on " << target_ << "." << std::endl;
    }
}

