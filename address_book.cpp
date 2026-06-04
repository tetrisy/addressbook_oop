#include "AddressBook.h"
#include "Contact.h"
#include "Menu.h"
#include "JsonAddressBookLoader.h"
#include "JsonAddressBookSaver.h"
#include <fstream>
#include <iostream>

int main() {
    AddressBook addressBook;

    JsonAddressBookLoader jsonLoader;
    addressBook.loadContacts(jsonLoader);
    
    Menu menu(addressBook);
    bool isWorking = true;

    while(isWorking) {
        menu.displayMenu();
        isWorking = menu.executeMenuOption();
    }

    JsonAddressBookSaver jsonSaver;

    if(addressBook.getWasAnyContactChanged()) {
        std::ofstream contactsFile("contacts.json");
        if (!addressBook.saveContacts(jsonSaver)) {
            std::cout << "Error! File couldn't be opened." << std::endl;
        }
    }


    return 0;
}
