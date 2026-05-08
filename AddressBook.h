#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "Contact.h"
#include <vector>
#include <iostream>

class AddressBook {
    private:
        std::vector<Contact> contacts;
    public:
        void displayMenu() {
            std::cout << "===== ADDRESS BOOK =====" << std::endl;
            std::cout << "1. Add contact" << std::endl;
            std::cout << "2. Display all contacts" << std::endl;
            std::cout << "3. Edit contact" << std::endl;
            std::cout << "4. Delete contact" << std::endl;
            std::cout << "5. Search contact" << std::endl;
            std::cout << "0. Exit" << std::endl << std::endl;
        }

};

#endif
