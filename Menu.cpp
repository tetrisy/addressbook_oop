#include "Menu.h"
#include "AddressBook.h"
#include <string>
#include <iostream>
#include <limits>

Menu::Menu(AddressBook& book) : addressbook(book) {}

void Menu::displayMenu() {
    std::cout << "===== ADDRESS BOOK =====" << std::endl;
    std::cout << "1. Add contact" << std::endl;
    std::cout << "2. Display all contacts" << std::endl;
    std::cout << "3. Edit contact" << std::endl;
    std::cout << "4. Delete contact" << std::endl;
    std::cout << "5. Search contact" << std::endl;
    std::cout << "0. Exit" << std::endl << std::endl;
}

bool Menu::executeMenuOption() {
    switch(Menu::getUserMenuChoice()) {
        case 1:;
            addressbook.createContact();;
            break;
        case 2:
            addressbook.displayAllContacts();
            break;
        case 3:;
            addressbook.editContact();
            break;
        case 4:
            addressbook.deleteContact();
            break;
        case 5:
            addressbook.searchContact();
            break;
        case 0:
            return false;
        default:
            std::cout << "Unexpected input. Choose between (1-6) or 0 to exit" << std::endl;
            break;
    }
    return true;
}

int Menu::getUserMenuChoice() {
    int choice;
    do {
        std::cout << "Choose option (1-5) or 0 to exit: ";
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number." << std::endl;
            continue;
        }
    } while (choice < 0 || choice > 5);
    std::cout << std::endl;
    return choice;
}
