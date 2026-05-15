#pragma once

#include "Contact.h"
#include <vector>
#include <iostream>

class AddressBook {
    private:
        std::vector<Contact> m_contacts;
        bool wasContactsChanged = false;
        
    public:
        void loadContacts();
        void saveContacts();
        void createContact();
        void editContact();
        void deleteContact();
        void searchContact();
        void displayAllContacts();
        void displayContact(const Contact& contact);

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
