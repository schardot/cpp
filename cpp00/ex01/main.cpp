#include "utils.h"
#include "Phonebook.h"
#include "Contact.h"

int main(void)
{
    std::string command;
    Phonebook pb;
    while (command != "EXIT")
    {
        std::cout << "Enter command: ADD, SEARCH or EXIT" << std::endl;
        std::cin >> command;
        if (command == "ADD")
        {
            Contact newContact = fillContact();
            pb.AddContact(newContact);
        }
        else if (command == "SEARCH")
        {
            pb.DisplayPhonebook();
        }
    }
    return (0);
}