#pragma once

#include "Contact.h"
#include <nlohmann/json.hpp>
#include <vector>
#include <iostream>

using json = nlohmann::ordered_json;

class AddressBook {
    private:
        std::vector<Contact> m_contacts;
        bool wasContactsChanged = false;
        
    public:
        void loadContacts(std::istream& fileStream);
        void saveContacts();
        void createContact();
        void editContact();
        void deleteContact();
        std::vector<int> searchContact();
        void displayAllContacts();
        void displayContact(const Contact& contact);
        int getUserID(int contactSize);
        void to_json(nlohmann::ordered_json& j, const Contact& contact);

        inline const std::vector<Contact>& getContacts() {
            return m_contacts;
        }

        inline void setContacts(std::vector<Contact> contacts) {
            m_contacts = contacts;
        }       

        inline const bool& getWasContactChanged() {
            return wasContactsChanged;
        }
};
