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
        int getID();
        void setID();
        std::string getFirstName();
        void setFirstName();
        std::string getLastName();
        void setLastName();
        std::string getPhoneNumber();
        void setPhoneNumber();
        std::string getEmail();
        void setEmail();
        std::string getStreet();
        void setStreet();
        std::string getCity();
        void setCity();
};

#endif
