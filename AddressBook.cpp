#include "Contact.h"
#include "AddressBook.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::ordered_json;

std::vector<Contact> AddressBook::getContacts() {
    return _contacts;
}

std::vector<Contact> AddressBook::loadContacts() {
    std::vector<Contact> contacts;
    std::ifstream file ("contacts.json");

    if (!file.is_open()) {
        std::cout << "No contacts to load." << std::endl;
        return contacts;
    }

    json jsonContacts;
    file >> jsonContacts;

    for (const auto& person : jsonContacts) {
        Contact contact(person["id"], person["firstName"], person["lastName"], person["phoneNumber"], person["email"], person["street"], person["city"]);
        contacts.push_back(contact);
    }

    std::cout << "Loaded " << contacts.size() << " contacts!" << std::endl << std::endl;
    file.close();

    return contacts;
}

void AddressBook::displayAllContacts(const std::vector<Contact>& contacts) {
    for(const Contact& contact : contacts) {
        AddressBook::displayContact(contact);
    }
}

void AddressBook::displayContact(const Contact& contact) {
    std::cout << "=== Contact information ===" << std::endl;
    std::cout << "ID: " << contact.getID() << std::endl;
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Email: " << contact.getEmail() << std::endl;
    std::cout << "Street: " << contact.getStreet() << std::endl;
    std::cout << "City: " << contact.getCity() << std::endl << std::endl;
}
