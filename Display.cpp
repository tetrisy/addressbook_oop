#include "Display.h"
#include <iostream>

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
