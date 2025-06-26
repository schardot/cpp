#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << BOLDGREEN << "RobotomyRequestForm constructed! " << std::endl << RESET;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << DIM << GRAY << "RobotomyRequestForm destructed. " << std::endl << RESET;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj), _target(obj._target) {
    std::cout << CYAN << "Copy!" << RESET << " New " << obj.getName() << " created." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
    if (this != &obj) {
        AForm::operator=(obj);
        _target = obj._target;
        std::cout << MAGENTA << "Copy assignment operator called!" << RESET << " Note that there's nothing unique to this form to be copied." << std::endl;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &obj) {
    std::cout << "Type: " << BOLDWHITE << obj.getName() << RESET
              << ", signed: " << BOLDWHITE << std::boolalpha << obj.getIsSigned() << RESET
              << ", sign grade: " << BOLDWHITE << obj.getMinSignGrade() << RESET
              << ", execution grade: " << BOLDWHITE << obj.getMinExecGrade() << RESET << std::endl;
    return (out);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    validateExecutionRequirements(executor);
    std::cout << "* Drilling noises *" << std::endl;
    std::srand(std::time(NULL));
    if (std::rand() % 2)
    {
        std::cout << _target << " has been robotomized successfully." << std::endl;
    }
    else
    {
        std::cout << "The robotomy failed on " << _target << "." << std::endl;
    }
}

