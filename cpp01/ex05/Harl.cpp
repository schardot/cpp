#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level) {
    std::string AllLevels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*AllMembers[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i ++) {
        if (AllLevels[i] == level) {
            (this->*AllMembers[i])();
            return;
        }
    }
}

void Harl::debug(void) {
    std::cout << "(Debug message) I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "(Info message) I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void){
    std::cout << "(Warning message) I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void){
    std::cout << "(Error message) This is unacceptable !I want to speak to the manager now." << std::endl;
}
