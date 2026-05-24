#pragma once

#include <string>
#include <iostream>

namespace NSContact {
    struct ContactDetails {
        std::string phoneNumber;
        std::string email;
        std::string street;
        std::string city;
    };
}

class Contact {
    private:
        int m_id;
        std::string m_firstName;
        std::string m_lastName;
        NSContact::ContactDetails details;
    public:
        Contact() = default;
        Contact(int id, std::string firstName, std::string lastName, NSContact::ContactDetails contactDetails = {});
        static bool phoneNumberValidation(const std::string& phoneNumber);
        static bool emailValidation(const std::string& email);
        void editDetails();
        static Contact getContactDetailsFromUser();

        inline const int& getID() const {
            return m_id;
        }

        inline void setID(int newID) {
            m_id = newID;
        }

        inline const std::string& getFirstName() const {
            return m_firstName;
        }

        inline void setFirstName(std::string newFirstName) {
            m_firstName = newFirstName;
        }

        inline const std::string& getLastName() const {
            return m_lastName;
        }

        inline void setLastName(std::string newLastName) {
            m_lastName = newLastName;
        }

        inline const std::string& getPhoneNumber() const {
            return details.phoneNumber;
        }

        inline void setPhoneNumber(std::string newPhoneNumber) {
            details.phoneNumber = newPhoneNumber;
        }

        inline const std::string& getEmail() const {
            return details.email;
        }

        inline void setEmail(std::string newEmail) {
            details.email = newEmail;
        }

        inline const std::string& getStreet() const {
            return details.street;
        }

        inline void setStreet(std::string newStreet) {
            details.street = newStreet;
        }

        inline const std::string& getCity() const {
            return details.city;
        }

        inline void setCity(std::string newCity) {
            details.city = newCity;
        }
};
