#ifndef UTILS_H
#define UTILS_H

#include "Contact.h"
#include <iostream>
#include <iomanip>

Contact fillContact();
void FormatField(std::string s);
void DisplayContact(Contact c, int i);
void DisplayFullContact(Contact c);

#endif
