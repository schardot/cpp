#include "Phonebook.h"

Phonebook::Phonebook() : currentContacts(0) {}

Phonebook::~Phonebook() {}

void Phonebook::AddContact(const Contact &contact)
{
    if (currentContacts < MAX_CONTACTS){
        contacts[currentContacts] = contact;
        currentContacts++;
    } else {
        contacts[0] = contact;
    }
}

void Phonebook::DisplayPhonebook(void) {
    std::cout << "|";
    FormatField("Index");
    FormatField("First Name");
    FormatField("Last Name");
    FormatField("Nickname");
    std::cout << std::endl;

    if (contacts[0].getFirstName().empty()) {
        std::cout << "No contacts found" << std::endl;
        return ;
    }

    int i = 0;

    while (i < MAX_CONTACTS) {
        DisplayContact(contacts[i], i);
        i++;
    }

    try {
        std::string index;
        std::cout << "Enter index of the entry to display" << std::endl;
        std::getline(std::cin, index);
        int ind;
        std::istringstream(index) >> ind;
        if (ind < 0 || ind >= MAX_CONTACTS) {
            std::cout << "Invalid index" << std::endl;
            return;
        }
        Contact newContact = getContactFromIndex(ind);
        if (newContact.getFirstName().empty())
            return;
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

Contact Phonebook::getContactFromIndex(int i) const
{
    if (i < 0 || i >= currentContacts)
    {
        std::cout << "Invalid index!" << std::endl;
        return Contact();
    }
    return contacts[i];
}

void DisplayContact(Contact c, int i) {
    std::cout << "|";

    std::ostringstream oss;
    oss << i;
    FormatField(oss.str());

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
        std::cout << std::setw(10) << s;
    }
    std::cout << "|";
}
