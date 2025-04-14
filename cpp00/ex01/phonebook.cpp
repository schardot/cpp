#include "utils.h"
#include "Phonebook.h"

void Phonebook::DisplayPhonebook(void) {
    std::cout << "|";
    FormatField("Index");
    FormatField("First Name");
    FormatField("Last Name");
    FormatField("Nickname");
    std::cout << std::endl;

    if (contacts.size() == 0) {
        std::cout << "No contacts found" << std::endl;
        return ;
    }

    int i = 0;

    while (i < contacts.size()) {
        DisplayContact(contacts[i], i);
        i++;
    }

    try {
        std::string index;
        std::cout << "Enter index of the entry to display" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, index);
        int ind = std::stoi(index);
        if (ind < 0 || ind >= contacts.size()) {
            std::cout << "Invalid index" << std::endl;
            return;
        }
        Contact newContact = getContactFromIndex(ind);
        DisplayFullContact(newContact);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Invalid input! Please enter a valid number." << std::endl;
    }
    catch (...)
    {
        std::cout << "An unexpected error occurred!" << std::endl;
    }
}

void DisplayContact(Contact c, int i) {
    std::cout << "|";
    FormatField(std::to_string(i));
    FormatField(c.getFirstName());
    FormatField(c.getLastName());
    FormatField(c.getNickname());
    std::cout << std::endl;
}

void DisplayFullContact(Contact c) {
    std::cout << c.getFirstName() << std::endl;
    std::cout << c.getLastName() << std::endl;
    std::cout << c.getNickname() << std::endl;
    std::cout << c.getPhoneNumber() << std::endl;
    std::cout << c.getDarkestSecret() << std::endl;
}

void FormatField(std::string s) {
    int len = s.length();
    if (len > 10)
        std::cout << s.substr(9) << ".";
    else {
        std::cout << std::setw(10);
        std::cout << s;
    }
    std::cout << "|";
}
