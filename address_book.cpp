#include "AddressBook.h"
#include "Contact.h"
#include "Menu.h"
#include <fstream>
#include <iostream>

int main() {
    AddressBook addressBook;
    std::ifstream contactsFile("contacts.json");

    if (!addressBook.loadContacts(contactsFile)) {
        std::cout << "Error! File couldn't be opened." << std::endl;
    }

    contactsFile.close();

    Menu menu(addressBook);
    bool isWorking = true;

    while(isWorking) {
        menu.displayMenu();
        isWorking = menu.executeMenuOption();
    }

    if(addressBook.getWasContactChanged()) {
        std::ofstream contactsFile("contacts.json");
        if (!addressBook.saveContacts(contactsFile)) {
            std::cout << "Error! File couldn't be opened." << std::endl;
        }
    }


    return 0;
}
