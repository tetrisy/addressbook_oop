#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class Contact {
    private:
        int _id;
        std::string _firstName;
        std::string _lastName;
        std::string _phoneNumber;
        std::string _email;
        std::string _street;
        std::string _city;
    public:
        Contact(int id, std::string firstName, std::string lastName, std::string phoneNumber, std::string email, std::string street, std::string city);
};

#endif
