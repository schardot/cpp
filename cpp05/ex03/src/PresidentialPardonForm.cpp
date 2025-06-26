#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << BOLDGREEN << "PresidentialPardonForm constructed! " << std::endl << RESET;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << DIM << GRAY << "PresidentialPardonForm destructed. " << std::endl << RESET;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj), _target(obj._target) {
    std::cout << CYAN << "Copy!" << RESET << " New " << obj.getName() << " created." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
    if (this != &obj) {
        AForm::operator=(obj);
        _target = obj._target;
        std::cout << MAGENTA << "Copy assignment operator called!" << RESET << " Note that there's nothing unique to this form to be copied." << std::endl;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &obj) {
    std::cout << "Type: " << BOLDWHITE << obj.getName() << RESET
              << ", signed: " << BOLDWHITE << std::boolalpha << obj.getIsSigned() << RESET
              << ", sign grade: " << BOLDWHITE << obj.getMinSignGrade() << RESET
              << ", execution grade: " << BOLDWHITE << obj.getMinExecGrade() << RESET << std::endl;
    return (out);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    validateExecutionRequirements(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

