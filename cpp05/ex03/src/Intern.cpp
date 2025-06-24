
#include "../include/Intern.hpp"

Intern::Intern()
{
    std::cout << BOLDGREEN << "Intern constructed! " << std::endl << RESET;
}

Intern::Intern(const Intern& obj)
{
    (void) obj;
    std::cout << CYAN << "Copy!" << RESET << " New intern created." << std::endl;
}

Intern::~Intern()
{
    std::cout << DIM << GRAY << "Intern destructed. " << std::endl << RESET;
}

Intern &Intern::operator=(const Intern &obj)
{
    if (this != &obj)
    {
        std::cout << MAGENTA << "Copy assignment operator called on intern!" << RESET << std::endl;
    }
    return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    if (formName.empty() || target.empty())
        return (NULL);

    const std::string availableForms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(Intern::*creators[3])(std::string const &) = { &Intern::createShrubberyForm, &Intern::createRobotomyForm, &Intern::createPresidentialForm};

    for (int i = 0; i < 3; i++)
    {
        if (availableForms[i] == formName)
        {
            std::cout << BOLDGREEN << "Success! " << RESET << "Intern creates " << formName << std::endl;
            return ((this->*creators[i])(target));
        }
    }

    std::cout << "Intern: " << BOLDRED << "form not found" << RESET << ": " << formName << std::endl;
    return NULL;
}

AForm* Intern::createShrubberyForm(std::string const &target) {
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::createPresidentialForm(std::string const &target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::createRobotomyForm(std::string const &target)
{
    return (new RobotomyRequestForm(target));
}