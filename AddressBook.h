#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "Contact.h"
#include <vector>
#include <iostream>

class AddressBook {
    private:
        std::vector<Contact> _contacts;
        bool wasContactsChanged = false;
        
    public:
        AddressBook(std::vector<Contact> contacts) {
            _contacts = contacts;
        }
        std::vector<Contact> loadContacts();
        void saveContacts(const std::vector<Contact>& contacts);
        Contact createContact(const std::vector<Contact>& contacts);
        void editContact(std::vector<Contact> &contacts);
        void deleteContact(std::vector<Contact> &contacts);
        void searchContact(const std::vector<Contact>& contacts);
        void displayAllContacts(const std::vector<Contact>& contacts);
        void displayContact(const Contact& contact);

        inline std::vector<Contact> AddressBook::getContacts() {
            return _contacts;
        }

        inline void AddressBook::setContacts(std::vector<Contact> contacts) {
            _contacts = contacts;
        }       

        inline bool AddressBook::getWasContactChanged() {
            return wasContactsChanged;
        }
};

#endif
