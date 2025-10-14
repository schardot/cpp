#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "Default Bureaucrat constructed!" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << GRAY << "Bureaucrat destructor called";
    if (!name_.empty())
        std::cout << " for " << name_ << " with grade " << grade_;
    std::cout << "." << RESET << std::endl;
}

void Bureaucrat::validateGrade(int grade) {
    if (grade < 1)
        throw(GradeTooHighException());
    else if (grade > 150)
        throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade)
{
    validateGrade(grade);
    std::cout << BOLDGREEN << "Bureaucrat " << name_ << " constructed! " << RESET << "Grade " << grade_ << "."<< std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) {
    grade_ = obj.grade_;
    std::cout << "New Bureaucrat created from copy of Bureaucrat " << name_ << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (this != &obj) {
        this->grade_ = obj.grade_;
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
    return (name_);
}

int Bureaucrat::getGrade() const {
    return (grade_);
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
        std::cout << name_ << BOLDBLUE << " signed " << RESET << obj.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << name_ << BOLDRED << " couldn't sign " << RESET << obj.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) {
    try {
        form.execute(*this);
        std::cout << name_ << BOLDMAGENTA << " executed " << RESET << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << name_ << BOLDRED << " couldn't execute " << RESET << form.getName() << " because " << e.what() << std::endl;
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