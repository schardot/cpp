#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << BOLDGREEN << "ShrubberyCreationForm constructed! " << std::endl << RESET;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << DIM << GRAY << "ShrubberyCreationForm destructed. " << std::endl << RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj), target_(obj.target_) {
    std::cout << CYAN << "Copy!" << RESET << " New " << obj.getName() << " created." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
    if (this != &obj) {
        AForm::operator=(obj);
        target_ = obj.target_;
        std::cout << MAGENTA << "Copy assignment operator called!" << RESET << std::endl;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &obj) {
    std::cout << "Type: " << BOLDWHITE << obj.getName() << RESET
              << ", signed: " << BOLDWHITE << std::boolalpha << obj.getIsSigned() << RESET
              << ", sign grade: " << BOLDWHITE << obj.getMinSignGrade() << RESET
              << ", execution grade: " << BOLDWHITE << obj.getMinExecGrade() << RESET << std::endl;
    return (out);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    validateExecutionRequirements(executor);
    std::ofstream myFile((_target + "_shrubbery").c_str());
    if (myFile) {
        myFile << "        /\\ \n"
                  "       /**\\ \n"
                  "      /****\\ \n"
                  "     /******\\ \n"
                  "    /********\\ \n"
                  "   /**********\\ \n"
                  "       |||| \n"
                  "       |||| \n";
    }
}

