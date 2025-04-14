#include "Contact.h"
#include "utils.h"

Contact fillContact() {
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
    std::cout << "Adding new contact:" << std::endl;
    while (firstName == "")
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "First name:" << std::endl;
        std::getline(std::cin, firstName);
    }
    while (lastName == "")
    {
        std::cout << "Last name:" << std::endl;
        std::getline(std::cin, lastName);
    }
    while (nickname == "")
    {
        std::cout << "Nickname:" << std::endl;
        std::getline(std::cin, nickname);
    }
    while (phoneNumber == "")
    {
        std::cout << "Phone number:" << std::endl;
        std::getline(std::cin, phoneNumber);
    }
    while (darkestSecret == "")
    {
        std::cout << "Darkest secret:" << std::endl;
        std::getline(std::cin, darkestSecret);
    }

    Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    return newContact;
}

