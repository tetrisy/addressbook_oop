#pragma once

#include "Contact.h"
#include "IAddressBookLoader.h"
#include <nlohmann/json.hpp>
#include <vector>
#include <iostream>

using json = nlohmann::ordered_json;

class AddressBook {
    private:
        std::vector<Contact> m_contacts;
        bool wasAnyContactsChanged = false;
        
    public:
        void loadContacts(IAddressBookLoader& load, std::istream& fileStream);
        bool saveContacts(std::ostream& fileStream);
        void createContact();
        void editContact();
        void deleteContact();
        std::vector<int> searchContact();
        void displayAllContacts();
        void displayContact(const Contact& contact);
        int getUserID(int contactSize);

        inline const std::vector<Contact>& getContacts() {
            return m_contacts;
        }

        inline void setContacts(std::vector<Contact> contacts) {
            m_contacts = contacts;
        }       

        inline const bool& getWasAnyContactChanged() {
            return wasAnyContactsChanged;
        }
};
