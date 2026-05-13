#include "Contact.h"
#include <regex>
#include <iostream>

Contact::Contact() {

}

Contact::Contact(int id, std::string firstName, std::string lastName, std::string phoneNumber, std::string email, std::string street, std::string city) {
    _id = id;
    _firstName = firstName;
    _lastName = lastName;
    _phoneNumber = phoneNumber;
    _email = email;
    _street = street;
    _city = city;
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
