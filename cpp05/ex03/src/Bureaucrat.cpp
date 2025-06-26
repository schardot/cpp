#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "Default Bureaucrat constructed!" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << GRAY << "Bureaucrat destructor called";
    if (!_name.empty())
        std::cout << " for " << _name << " with grade " << _grade;
    std::cout << "." << RESET << std::endl;
}

void Bureaucrat::validateGrade(int grade) {
    if (grade < 1)
        throw(GradeTooHighException());
    else if (grade > 150)
        throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    validateGrade(grade);
    std::cout << BOLDGREEN << "Bureaucrat " << name << " constructed! " << RESET << "Grade " << grade << "."<< std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) {
    _grade = obj._grade;
    std::cout << "New Bureaucrat created from copy of Bureaucrat " << _name << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (this != &obj) {
        this->_grade = obj._grade;
    }
    std::cout << "Default Bureaucrat copy assignment called!" << std::endl;
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
    std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
    return out;
}

const std::string &Bureaucrat::getName() const {
    return (_name);
}

int Bureaucrat::getGrade() const {
    return (_grade);
}

void Bureaucrat::incrementGrade() {
    validateGrade(_grade + 1);
    _grade += 1;
    std::cout << _name << "'s grade incremented, now: " << _grade << std::endl;
}

void Bureaucrat::decrementGrade() {
    validateGrade(_grade - 1);
    _grade -= 1;
    std::cout << _name << "'s grade decremented, now: " << _grade << std::endl;
}

void Bureaucrat::signForm(AForm &obj) {

    try {
        obj.beSigned(*this);
        std::cout << _name << BOLDBLUE << " signed " << RESET << obj.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << _name << BOLDRED << " couldn't sign " << RESET << obj.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) {
    try {
        form.execute(*this);
        std::cout << _name << BOLDMAGENTA << " executed " << RESET << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << BOLDRED << " couldn't execute " << RESET << form.getName() << " because " << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high! Highest grade possible is 1.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low! Lowest grade possible is 150.";
}