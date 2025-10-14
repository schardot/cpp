#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target_(target) {
    std::cout << BOLDGREEN << "PresidentialPardonForm constructed! " << std::endl << RESET;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << DIM << GRAY << "PresidentialPardonForm destructed. " << std::endl << RESET;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj), target_(obj.target_) {
    std::cout << CYAN << "Copy!" << RESET << " New " << obj.getName() << " created." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
    if (this != &obj) {
        AForm::operator=(obj);
        target_ = obj.target_;
        std::cout << MAGENTA << "Copy assignment operator called!" << RESET << std::endl;
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
    std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

