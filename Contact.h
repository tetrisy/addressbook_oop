#pragma once

#include <string>
#include <iostream>

class Contact {
    private:
        int m_id;
        std::string m_firstName;
        std::string m_lastName;
        std::string m_phoneNumber;
        std::string m_email;
        std::string m_street;
        std::string m_city;
    public:
        Contact() = default;
        Contact(int id, std::string firstName, std::string lastName, std::string phoneNumber, std::string email, std::string street, std::string city);
        static bool phoneNumberValidation(const std::string& phoneNumber);
        static bool emailValidation(const std::string& email);

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
            return m_phoneNumber;
        }

        inline void setPhoneNumber(std::string newPhoneNumber) {
            m_phoneNumber = newPhoneNumber;
        }

        inline const std::string& getEmail() const {
            return m_email;
        }

        inline void setEmail(std::string newEmail) {
            m_email = newEmail;
        }

        inline const std::string& getStreet() const {
            return m_street;
        }

        inline void setStreet(std::string newStreet) {
            m_street = newStreet;
        }

        inline const std::string& getCity() const {
            return m_city;
        }

        inline void setCity(std::string newCity) {
            m_city = newCity;
        }
};
