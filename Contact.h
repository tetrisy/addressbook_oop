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
        Contact() = default;
        Contact(int id, std::string firstName, std::string lastName, std::string phoneNumber, std::string email, std::string street, std::string city);
        bool phoneNumberValidation(const std::string& phoneNumber);
        bool emailValidation(const std::string& email);

        const inline int& getID() const {
            return _id;
        }

        inline void setID(int newID) {
            _id = newID;
        }

        const inline std::string& getFirstName() const {
            return _firstName;
        }

        inline void setFirstName(std::string newFirstName) {
            _firstName = newFirstName;
        }

        const inline std::string& getLastName() const {
            return _lastName;
        }

        inline void setLastName(std::string newLastName) {
            _lastName = newLastName;
        }

        const inline std::string& getPhoneNumber() const {
            return _phoneNumber;
        }

        inline void setPhoneNumber(std::string newPhoneNumber) {
            _phoneNumber = newPhoneNumber;
        }

        const inline std::string& getEmail() const {
            return _email;
        }

        inline void setEmail(std::string newEmail) {
            _email = newEmail;
        }

        const inline std::string& getStreet() const {
            return _street;
        }

        inline void setStreet(std::string newStreet) {
            _street = newStreet;
        }

        const inline std::string& getCity() const {
            return _city;
        }

        inline void setCity(std::string newCity) {
            _city = newCity;
        }
};

#endif
