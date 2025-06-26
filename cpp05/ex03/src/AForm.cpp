#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm(const std::string &name, int MinSignGrade, int MinExecGrade) : _name(name), _MinSignGrade(MinSignGrade), _MinExecGrade(MinExecGrade) {
    validateGrade(MinSignGrade);
    validateGrade(MinExecGrade);
    _isSigned = false;
    std::cout << BOLDGREEN << "AForm constructed!" << RESET << std::endl;
}

AForm::~AForm()
{
    std::cout << DIM << GRAY << "AForm destructed. " << RESET << std::endl;
}

AForm::AForm(const AForm &obj) : _name(obj._name), _isSigned(obj._isSigned), _MinSignGrade(obj._MinSignGrade), _MinExecGrade(obj._MinExecGrade) {
    std::cout << CYAN << "Copy!" << RESET << " New AForm created. " << std::endl;
}

AForm &AForm::operator=(const AForm &obj) {
    if (this != &obj) {
        _isSigned = obj._isSigned;
        std::cout << MAGENTA << "Copy assignment operator called!" << RESET << " Now \"" << _name << "\" copied \"" << obj._name << "\"'s isSigned bool!" << std::endl;
    }
    return *this;
}

const std::string &AForm::getName() const     { return (_name); }
const bool &AForm::getIsSigned() const        { return (_isSigned); }
const int &AForm::getMinSignGrade() const     { return (_MinSignGrade); }
const int &AForm::getMinExecGrade() const     { return (_MinExecGrade); }

bool AForm::beSigned(const Bureaucrat &obj) {
    if (obj.getGrade() <= _MinSignGrade) {
        _isSigned = true;
    }
    else
        throw GradeTooLowException();
    return (_isSigned);
}

std::ostream &operator<<(std::ostream &out, const AForm &obj){
    std::cout << "AForm " << BOLDWHITE << obj.getName() << RESET
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
    return "Form not signed! Form must signed in order to execute.";
}

void AForm::validateExecutionRequirements(Bureaucrat const &executor) const {
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _MinExecGrade)
        throw GradeTooLowException();
}
