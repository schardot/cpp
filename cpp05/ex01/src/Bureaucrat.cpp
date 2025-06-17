#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "Default Bureaucrat constructed!" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called";
    if (!name.empty())
        std::cout << " for " << name << " with grade " << grade;
    std::cout << std::endl;
}

void Bureaucrat::validateGrade(int grade) {
    if (grade < 1)
        throw(GradeTooHighException());
    else if (grade > 150)
        throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    validateGrade(grade);
    std::cout << "Bureaucrat " << name << " constructed with grade " << grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) {
    grade = obj.grade;
    std::cout << "New Bureaucrat created from copy of Bureaucrat " << name << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (this != &obj) {
        this->grade = obj.grade;
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
    return (name);
}

int Bureaucrat::getGrade() const {
    return (grade);
}

void Bureaucrat::incrementGrade() {
    validateGrade(grade + 1);
    grade += 1;
    std::cout << name << "'s grade incremented, now: " << grade << std::endl;
}

void Bureaucrat::decrementGrade() {
    validateGrade(grade - 1);
    grade -= 1;
    std::cout << name << "'s grade decremented, now: " << grade << std::endl;
}

void Bureaucrat::signForm(Form &obj) {

    try {
        obj.beSigned(*this);
        std::cout << name << " signed " << obj.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << name << BOLDRED << " couldn't sign " << RESET << obj.getName() << " because " << e.what() << std::endl;
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