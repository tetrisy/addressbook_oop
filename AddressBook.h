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
        void displayMenu();
        std::vector<Contact> loadContacts();
};

#endif
