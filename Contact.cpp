#include "Contact.h"
#include "Utils.h"
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

Contact Contact::getContactDetailsFromUser() {
    Contact contact;
    std::string phoneNumber;
    std::string email;
    std::cout << "Enter first name: ";
    contact.setFirstName(Utils::getUserInputLine());
    std::cout << "Enter last name: ";
    contact.setLastName(Utils::getUserInputLine());
    do { 
        std::cout << "Enter phone number: ";
        phoneNumber = Utils::getUserInputLine();
        if(contact.Contact::phoneNumberValidation(phoneNumber)) {
            contact.setPhoneNumber(phoneNumber);
            break;
        } else {
            std::cout << "Invalid phone number! Enter a valid phone number." << std::endl;
        }
    } while(true);
    do {
        std::cout << "Enter email: ";
        email = Utils::getUserInputLine();
        if(contact.Contact::emailValidation(email)) {
            contact.setEmail(email);
            break;
        } else {
            std::cout << "Invalid email! Enter a valid email address." << std::endl;
        }
    } while(true);
    std::cout << "Enter street: ";
    contact.setStreet(Utils::getUserInputLine());
    std::cout << "Enter city: ";
    contact.setCity(Utils::getUserInputLine());
    std::cout << std::endl;

    return contact;
}
