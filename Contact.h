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
        int getID() const;
        void setID(int newID);
        std::string getFirstName() const;
        void setFirstName(std::string newFirstName);
        std::string getLastName() const;
        void setLastName(std::string newLastName);
        std::string getPhoneNumber() const;
        void setPhoneNumber(std::string newPhoneNumber);
        std::string getEmail() const;
        void setEmail(std::string newEmail);
        std::string getStreet() const;
        void setStreet(std::string newStreet);
        std::string getCity() const;
        void setCity(std::string newCity);
};

#endif
