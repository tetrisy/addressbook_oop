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

void AddressBook::setContacts(std::vector<Contact> contacts) {
    _contacts = contacts;
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

Contact AddressBook::addContact(std::vector<Contact> &contacts) {
    Contact contact;
    std::cout << "==== Adding contact menu ====" << std::endl; 
    contact.setID(contacts.size() + 1);
    std::cout << "Enter first name: ";
    std::cin.ignore();
    std::string firstName;
    std::getline(std::cin, firstName);
    contact.setFirstName(firstName);
    std::cout << "Enter last name: ";
    std::string lastName;
    std::getline(std::cin, lastName);
    contact.setLastName(lastName);
    std::string phoneNumber;
    do {
        std::cout << "Enter phone number: ";
        std::cin >> phoneNumber;
        contact.setPhoneNumber(phoneNumber);
    } while(!contact.Contact::phoneNumberValidation(phoneNumber));
    std::string email;
    do {
        std::cout << "Enter email: ";
        std::cin >> email;
        contact.setEmail(email);
    } while(!contact.Contact::emailValidation(email));
    std::cout << "Enter street: ";
    std::cin.ignore();
    std::string street;
    std::getline(std::cin, street);
    contact.setStreet(street);
    std::cout << "Enter city: ";
    std::string city;
    std::getline(std::cin, city);
    contact.setCity(city);
    std::cout << std::endl;

    return contact;
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
