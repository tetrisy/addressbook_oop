#include "Contact.h"
#include <regex>
#include <iostream>

Contact::Contact(int id, std::string firstName, std::string lastName, NSContact::ContactDetails contactDetails)
    : m_id(id), m_firstName(firstName), m_lastName(lastName), details(contactDetails)
{
}

bool Contact::phoneNumberValidation(const std::string& phoneNumber) {
    const std::regex phoneReg("^\\d{9}$");
    
    if(std::regex_match(phoneNumber, phoneReg)) {
        return true;
    } else {
        return false;
    }
}

bool Contact::emailValidation(const std::string& email) {
    const std::regex emailReg(R"([a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

    if(std::regex_match(email, emailReg)) {
        return true;
    } else {
        return false;
    }
}
