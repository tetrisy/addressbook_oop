#include "AddressBook.h"
#include "Contact.h"
#include "Menu.h"
#include <iostream>

int main() {
    AddressBook addressBook;
    addressBook.loadContacts();
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
