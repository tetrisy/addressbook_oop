#include "AddressBook.h"
#include "Contact.h"
#include "Menu.h"
#include "JsonAddressBookLoader.h"
#include "JsonAddressBookSaver.h"
#include "CLI/App.hpp"
#include "CLI/Formatter.hpp"
#include "CLI/Config.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
    AddressBook addressBook;
    CLI::App app;
    std::filesystem::path fileName;

    app.add_option("-f", fileName);
    CLI11_PARSE(app, argc, argv);

    JsonAddressBookLoader jsonLoader;
    addressBook.loadContacts(jsonLoader, fileName);
    
    Menu menu(addressBook);
    bool isWorking = true;

    while(isWorking) {
        menu.displayMenu();
        isWorking = menu.executeMenuOption();
    }

    JsonAddressBookSaver jsonSaver;

    if(addressBook.getWasAnyContactChanged()) {
        std::ofstream contactsFile("contacts.json");
        if (!addressBook.saveContacts(jsonSaver, fileName)) {
            std::cout << "Error! File couldn't be opened." << std::endl;
        }
    }


    return 0;
}
