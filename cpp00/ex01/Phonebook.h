#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <vector>
#include "Contact.h"

class Phonebook {
    private:
        std::vector<Contact> contacts;

    public:
        Phonebook() {};

        void AddContact(Contact contact)
        {
            if (contacts.size() == 8)
                contacts[0] = contact;
            else
                contacts.push_back(contact);
        }
        void DisplayPhonebook(void);
        Contact getContactFromIndex(int i) { return contacts[i]; }
};

#endif