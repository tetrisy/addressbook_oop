#include "Display.h"

void Display::displayContact(const Contact& contact) {
    std::cout << "=== Contact information ===" << std::endl;
    std::cout << "ID: " << contact.getID() << std::endl;
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Email: " << contact.getEmail() << std::endl;
    std::cout << "Street: " << contact.getStreet() << std::endl;
    std::cout << "City: " << contact.getCity() << std::endl << std::endl;
};

void Display::displayInvalidInputNotNumber() {
    std::cout << "Invalid input! Please enter a number." << std::endl;
}

void Display::displayDeletionConfirmation() {
    std::cout << "Contact deleted!" << std::endl;
}

void Display::promptForNameOrNumber() {
    std::cout << "Enter name or phone number to search: ";
}

void Display::displayNothingFound() {
    std::cout << "Nothing found." << std::endl;
}

void Display::displayHowManyFound(int amount) {
    std::cout << std::endl << "Found " << amount << " contacts." << std::endl << std::endl;

}
