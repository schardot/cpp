#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form(const std::string &name, int MinSignGrade, int MinExecGrade) : _name(name), _MinSignGrade(MinSignGrade), _MinExecGrade(MinExecGrade) {
    validateGrade(MinSignGrade);
    validateGrade(MinExecGrade);
    _isSigned = false;
    std::cout << BOLDGREEN << "Form constructed! " << RESET << *this;
}

Form::~Form()
{
    std::cout << DIM << GRAY << "Form destructed. " << RESET << *this;
}

Form::Form(const Form &obj) : _name(obj._name), _isSigned(obj._isSigned), _MinSignGrade(obj._MinSignGrade), _MinExecGrade(obj._MinExecGrade) {
    std::cout << CYAN << "Copy!" << RESET << " New form created. Form is a copy of: " << obj << std::endl;
}

Form &Form::operator=(const Form &obj) {
    if (this != &obj) {
        _isSigned = obj._isSigned;
        std::cout << MAGENTA << "Copy assignment operator called!" << RESET << " Now \"" << _name << "\" copied \"" << obj._name << "\"'s isSigned bool!" << std::endl;
    }
    return *this;
}

const std::string &Form::getName() const     { return (_name); }
const bool &Form::getIsSigned() const        { return (_isSigned); }
const int &Form::getMinSignGrade() const     { return (_MinSignGrade); }
const int &Form::getMinExecGrade() const     { return (_MinExecGrade); }

bool Form::beSigned(const Bureaucrat &obj) {
    if (obj.getGrade() <= _MinSignGrade) {
        _isSigned = true;
    }
    else
        throw GradeTooLowException();
    return (_isSigned);
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