#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm(const std::string &name, int MinSignGrade, int MinExecGrade) : name_(name), MinSignGrade_(MinSignGrade), MinExecGrade_(MinExecGrade) {
    validateGrade(MinSignGrade);
    validateGrade(MinExecGrade);
    isSigned_ = false;
    std::cout << BOLDGREEN << "AForm constructed!" << RESET << std::endl;
}

AForm::~AForm()
{
    std::cout << DIM << GRAY << "AForm destructed. " << RESET << std::endl;
}

AForm::AForm(const AForm &obj) : name_(obj.name_), isSigned_(obj.isSigned_), MinSignGrade_(obj.MinSignGrade_), MinExecGrade_(obj.MinExecGrade_) {
    std::cout << CYAN << "Copy!" << RESET << " New AForm created. " << std::endl;
}

AForm &AForm::operator=(const AForm &obj) {
    if (this != &obj) {
        isSigned_ = obj.isSigned_;
        std::cout << MAGENTA << "Copy assignment operator called!" << RESET << " Now \"" << name_ << "\" copied \"" << obj.name_ << "\"'s isSigned bool!" << std::endl;
    }
    return *this;
}

const std::string &AForm::getName() const     { return (name_); }
const bool &AForm::getIsSigned() const        { return (isSigned_); }
const int &AForm::getMinSignGrade() const     { return (MinSignGrade_); }
const int &AForm::getMinExecGrade() const     { return (MinExecGrade_); }

bool AForm::beSigned(const Bureaucrat &obj) {
    if (obj.getGrade() <= MinSignGrade_) {
        isSigned_ = true;
    }
    else
        throw GradeTooLowException();
    return (isSigned_);
}

std::ostream &operator<<(std::ostream &out, const AForm &obj){
    std::cout << "AForm type " << BOLDWHITE << obj.getName() << RESET
              << ", signed: " << BOLDWHITE << std::boolalpha << obj.getIsSigned() << RESET
              << ", sign grade: " << BOLDWHITE << obj.getMinSignGrade() << RESET
              << ", execution grade: " << BOLDWHITE << obj.getMinExecGrade() << RESET << std::endl;
    return (out);
}

void AForm::validateGrade(int grade)
{
    if (grade < 1)
        throw(GradeTooHighException());
    else if (grade > 150)
        throw(GradeTooLowException());
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form not signed! Form must be signed in order to execute.";
}

void AForm::validateExecutionRequirements(Bureaucrat const &executor) const {
    if (!isSigned_)
        throw FormNotSignedException();
    if (executor.getGrade() > MinExecGrade_)
        throw GradeTooLowException();
}
