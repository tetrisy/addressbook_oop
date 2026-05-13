#include "AddressBook.h"
#include "Menu.h"
#include "Contact.h"
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

    if(addressBook.getWasContactChanged()) {
        addressBook.saveContacts();
    }

    return 0;
}
