#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

class Contact {
    private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    public:
    Contact() {};

    Contact(const std::string& firstNameParam, const std::string& lastNameParam,
            const std::string& nicknameParam, const std::string& phoneNumberParam,
            const std::string& darkestSecretParam)
        : firstName(firstNameParam),
        lastName(lastNameParam),
        nickname(nicknameParam),
        phoneNumber(phoneNumberParam),
        darkestSecret(darkestSecretParam)
    {}

    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getNickname() const { return nickname; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getDarkestSecret() const { return darkestSecret; }
};

Contact fillContact();

#endif
