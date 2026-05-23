#include "AddressBook.h"
#include "Contact.h"
#include "Menu.h"
#include <fstream>
#include <iostream>

int main() {
    AddressBook addressBook;
    std::ifstream contactsFile("contacts.json");

     if(contactsFile.fail()) {
        std::cout << "Error! File couldn't be opened." << std::endl;
        return 1;
    }

    if (!contactsFile.is_open()) {
        std::cout << "No contacts to load." << std::endl;
        return 2;
    }

    addressBook.loadContacts(contactsFile);

    Menu menu(addressBook);
    bool isWorking= true;

    while(isWorking) {
        menu.displayMenu();
        isWorking = menu.executeMenuOption();
    }

    // if(addressBook.getWasContactChanged()) {
    //     addressBook.saveContacts();
    // }

    addressBook.saveContacts();

    return 0;
}
