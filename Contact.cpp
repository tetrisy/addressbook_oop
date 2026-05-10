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

int Contact::getID() const {
    return _id;
}

void Contact::setID(int newID) {
    _id = newID;
}

std::string Contact::getFirstName() const {
    return _firstName;
}

void Contact::setFirstName(std::string newFirstName) {
    _firstName = newFirstName;
}

std::string Contact::getLastName() const {
    return _lastName;
}

void Contact::setLastName(std::string newLastName) {
    _lastName = newLastName;
}

std::string Contact::getPhoneNumber() const {
    return _phoneNumber;
}

void Contact::setPhoneNumber(std::string newPhoneNumber) {
    _phoneNumber = newPhoneNumber;
}

std::string Contact::getEmail() const {
    return _email;
}

void Contact::setEmail(std::string newEmail) {
    _email = newEmail;
}

std::string Contact::getStreet() const {
    return _street;
}

void Contact::setStreet(std::string newStreet) {
    _street = newStreet;
}

std::string Contact::getCity() const {
    return _city;
}

void Contact::setCity(std::string newCity) {
    _city = newCity;
}
