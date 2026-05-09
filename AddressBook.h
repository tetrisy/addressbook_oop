#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "Contact.h"
#include <vector>
#include <iostream>

class AddressBook {
    private:
        std::vector<Contact> _contacts;
    public:
        AddressBook(std::vector<Contact> contacts) {
            _contacts = contacts;
        }
        std::vector<Contact> loadContacts();
        Contact addContact(std::vector<Contact> &contacts);
        void displayAllContacts(const std::vector<Contact>& contacts);
        void displayContact(const Contact& contact);
        std::vector<Contact> getContacts();
        void setContacts(std::vector<Contact> contacts);
};

#endif
