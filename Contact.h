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
        void setID(int newID);
        std::string getFirstName();
        void setFirstName(std::string newFirstName);
        std::string getLastName();
        void setLastName(std::string newLastName);
        std::string getPhoneNumber();
        void setPhoneNumber(std::string newPhoneNumber);
        std::string getEmail();
        void setEmail(std::string newEmail);
        std::string getStreet();
        void setStreet(std::string newStreet);
        std::string getCity();
        void setCity(std::string newCity);
};

#endif
