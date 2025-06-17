#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form(const std::string &name, int MinSignGrade, int MinExecGrade) : name(name), MinSignGrade(MinSignGrade), MinExecGrade(MinExecGrade) {
    validateGrade(MinSignGrade);
    validateGrade(MinExecGrade);
    isSigned = false;
    std::cout << BOLDGREEN << "Form constructed! " << RESET << *this;
}

Form::~Form()
{
    std::cout << DIM << GRAY << "Form destructed. " << RESET << *this;
}

Form::Form(const Form &obj) : name(obj.name), isSigned(obj.isSigned), MinSignGrade(obj.MinSignGrade), MinExecGrade(obj.MinExecGrade) {
    std::cout << CYAN << "Copy!" << RESET << " New form created. Form is a copy of: " << obj << std::endl;
}

Form &Form::operator=(const Form &obj) {
    if (this != &obj) {
        isSigned = obj.isSigned;
        std::cout << MAGENTA << "Copy assignment operator called!" << RESET << " Now \"" << name << "\" copied \"" << obj.name << "\"'s isSigned bool!" << std::endl;
    }
    return *this;
}

const std::string &Form::getName() const     { return (name); }
const bool &Form::getIsSigned() const        { return (isSigned); }
const int &Form::getMinSignGrade() const     { return (MinSignGrade); }
const int &Form::getMinExecGrade() const     { return (MinExecGrade); }

bool Form::beSigned(const Bureaucrat &obj) {
    if (obj.getGrade() <= MinSignGrade) {
        isSigned = true;
    }
    else
        throw GradeTooLowException();
    return (isSigned);
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