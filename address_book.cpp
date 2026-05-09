#include "AddressBook.h"
#include "Menu.h"
#include "Contact.h"
#include <iostream>
// #include <string>
// #include <vector>
// #include <regex>
// #include <fstream>
// #include <nlohmann/json.hpp>
// using json = nlohmann::ordered_json;

int main() {
    AddressBook addressBook(addressBook.loadContacts());
    Menu menu(addressBook);
    bool isWorking= true;

    while(isWorking) {
        menu.displayMenu();
        isWorking = menu.executeMenuOption();
    }

    return 0;
}
