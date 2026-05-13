#pragma once

#include "Contact.h"
#include "AddressBook.h"
#include <vector>
#include <iostream>

class Menu {
    private:
        AddressBook& addressbook;
    public:
        Menu(AddressBook& book);
        void displayMenu();
        bool executeMenuOption();
        int getUserMenuChoice();
};
