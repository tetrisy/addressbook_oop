#include "Contact.h"

Contact::Contact(int id, std::string firstName, std::string lastName, std::string phoneNumber, std::string email, std::string street, std::string city) {
    _id = id;
    _firstName = firstName;
    _lastName = lastName;
    _phoneNumber = phoneNumber;
    _email = email;
    _street = street;
    _city = city;
}
