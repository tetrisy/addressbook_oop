#include "AddressBook.h"
#include "Contact.h"
#include "Menu.h"
#include "JsonAddressBookLoader.h"
#include <fstream>
#include <iostream>

int main() {
    AddressBook addressBook;
    std::ifstream contactsFile("contacts.json");

    JsonAddressBookLoader jsonLoader;
    addressBook.loadContacts(jsonLoader, contactsFile);
    
    Menu menu(addressBook);
    bool isWorking = true;

    while(isWorking) {
        menu.displayMenu();
        isWorking = menu.executeMenuOption();
    }

    if(addressBook.getWasAnyContactChanged()) {
        std::ofstream contactsFile("contacts.json");
        if (!addressBook.saveContacts(contactsFile)) {
            std::cout << "Error! File couldn't be opened." << std::endl;
        }
    }


    return 0;
}
