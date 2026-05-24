#pragma once

#include "AddressBook.h"
#include "Contact.h"
#include <vector>
#include <iostream>

class Menu {
    private:
        AddressBook& addressbook;
    public:
        Menu(AddressBook& book);
        void displayMenu();
        void displayCreateContactMenu();
        bool executeMenuOption();
        int getUserMenuChoice();
};
