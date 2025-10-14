#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form(const std::string &name, int MinSignGrade, int MinExecGrade)
    : name_(name), isSigned_(false), MinSignGrade_(MinSignGrade), MinExecGrade_(MinExecGrade) {
    validateGrade(MinSignGrade);
    validateGrade(MinExecGrade);
    _isSigned = false;
    std::cout << BOLDGREEN << "Form constructed! " << RESET << *this;
}

Form::~Form()
{
    std::cout << DIM << GRAY << "Form destructed. " << RESET << *this;
}

Form::Form(const Form &obj) : name_(obj.name_), isSigned_(obj.isSigned_), MinSignGrade_(obj.MinSignGrade_), MinExecGrade_(obj.MinExecGrade_) {
    std::cout << CYAN << "Copy!" << RESET << " New form created. Form is a copy of: " << obj << std::endl;
}

Form &Form::operator=(const Form &obj) {
    if (this != &obj) {
        isSigned_ = obj.isSigned_;
        std::cout << MAGENTA << "Copy assignment operator called!" << RESET << " \"" << name_ << "\" copied \"" << obj.name_ << "\"." << std::endl;
    }
    return *this;
}

bool Form::beSigned(const Bureaucrat &obj) {
    if (obj.getGrade() <= _MinSignGrade) {
        _isSigned = true;
    }
    else
        throw GradeTooLowException();
    return (isSigned_);
}

std::ostream &operator<<(std::ostream &out, const Form &obj){
    std::cout << "Form " << BOLDWHITE << obj.getName() << RESET
              << ", signed: " << BOLDWHITE << std::boolalpha << obj.getIsSigned() << RESET
              << ", sign grade: " << BOLDWHITE << obj.getMinSignGrade() << RESET
              << ", execution grade: " << BOLDWHITE << obj.getMinExecGrade() << RESET << std::endl;
    return (out);
}

void Form::validateGrade(int grade)
{
    if (grade < 1)
        throw(GradeTooHighException());
    else if (grade > 150)
        throw(GradeTooLowException());
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade too high! Highest grade possible is 1.";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade too low! Lowest grade possible is 150.";
}