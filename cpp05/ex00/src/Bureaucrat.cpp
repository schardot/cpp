#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "Default Bureaucrat constructed!" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called";
    if (!name_.empty())
        std::cout << " for " << name_ << " with grade " << grade_;
    std::cout << std::endl;
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
    std::cout << "Bureaucrat " << name << " constructed with grade " << grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name_(obj.name_), grade_(obj.grade_)
{
    std::cout << "New Bureaucrat created from copy of Bureaucrat " << obj.name_ << std::endl;
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
    validateGrade(grade_ - 1);
    grade_ -= 1;
    std::cout << name_ << "'s grade incremented, now: " << grade_ << std::endl;
}

void Bureaucrat::decrementGrade() {
    validateGrade(grade_ + 1);
    grade_ += 1;
    std::cout << name_ << "'s grade decremented, now: " << grade_ << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high! Highest grade possible is 1.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low! Lowest grade possible is 150.";
}