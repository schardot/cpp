#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"

class Phonebook {
	private:
		static const int MAX_CONTACTS = 8;
		Contact contacts[MAX_CONTACTS];
		int currentContacts;

	public:
		Phonebook();
		~Phonebook();
		Phonebook(const Phonebook &other);
		Phonebook &operator=(const Phonebook &other);

		void AddContact(const Contact &contact);
		void DisplayPhonebook(void);
		Contact getContactFromIndex(int i) const;
};

void DisplayContact(Contact c, int i);
void DisplayFullContact(Contact c);
void FormatField(std::string s);

#endif