#include "Contact.h"
#include "AddressBook.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::ordered_json;

std::string toLower(std::string phrase) {
    for (char& c : phrase) {
        c = tolower(c);
    }

    return phrase;
}

std::vector<Contact> AddressBook::getContacts() {
    return _contacts;
}

void AddressBook::setContacts(std::vector<Contact> contacts) {
    _contacts = contacts;
}

bool AddressBook::getWasContactChanged() {
    return wasContactsChanged;
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

void AddressBook::saveContacts(const std::vector<Contact>& contacts) {
    json jsonContacts = json::array();

    json person;

    for (const Contact& contact : contacts) {
        person["id"] = contact.getID();
        person["firstName"] = contact.getFirstName();
        person["lastName"] = contact.getLastName();
        person["phoneNumber"] = contact.getPhoneNumber();
        person["email"] = contact.getEmail();
        person["street"] = contact.getStreet();
        person["city"] = contact.getCity();

        jsonContacts.push_back(person);
    }

    std::ofstream file("contacts.json");
    file << jsonContacts.dump(4);
    file.close();
}

Contact AddressBook::createContact(const std::vector<Contact>& contacts) {
    Contact contact;
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string email;
    std::string street;
    std::string city;

    std::cout << "==== Adding contact menu ====" << std::endl; 
    contact.setID(contacts.size() + 1);
    std::cout << "Enter first name: ";
    std::cin.ignore();
    std::getline(std::cin, firstName);
    contact.setFirstName(firstName);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
    contact.setLastName(lastName);
    do {
        std::cout << "Enter phone number: ";
        std::cin >> phoneNumber;
        contact.setPhoneNumber(phoneNumber);
        if(contact.Contact::phoneNumberValidation(phoneNumber)) {
            break;
        } else {
            std::cout << "Invalid phone number! Enter a valid phone number." << std::endl;
        }
    } while(true);
    do {
        std::cout << "Enter email: ";
        std::cin >> email;
        contact.setEmail(email);
        if(contact.Contact::emailValidation(email)) {
            break;
        } else {
            std::cout << "Invalid email! Enter a valid email address." << std::endl;
        }
    } while(true);
    std::cout << "Enter street: ";
    std::cin.ignore();
    std::getline(std::cin, street);
    contact.setStreet(street);
    std::cout << "Enter city: ";
    std::getline(std::cin, city);
    contact.setCity(city);
    std::cout << std::endl;

    wasContactsChanged = true;

    return contact;
}

void AddressBook::editContact(std::vector<Contact> &contacts) {
    int editID;
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string email;
    std::string street;
    std::string city;
    Contact contact;

    do {
        std::cout << "Enter ID of contact you want to edit: ";
        std::cin >> editID;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number." << std::endl;
            editID = -1;
            continue;
        }

    } while (editID < 1 || editID > contacts.size());
    contact.setID(contacts[editID - 1].getID());
    std::cout << "Enter first name: ";
    std::cin.ignore();
    std::getline(std::cin, firstName);
    contact.setFirstName(firstName);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
    contact.setLastName(lastName);
    do {
        std::cout << "Enter phone number: ";
        std::cin >> phoneNumber;
        contact.setPhoneNumber(phoneNumber);
        if(contact.Contact::phoneNumberValidation(phoneNumber)) {
            break;
        } else {
            std::cout << "Invalid phone number! Enter a valid phone number." << std::endl;
        }
    } while(true);
    do {
        std::cout << "Enter email: ";
        std::cin >> email;
        contact.setEmail(email);
        if(contact.Contact::emailValidation(email)) {
            break;
        } else {
            std::cout << "Invalid email! Enter a valid email address." << std::endl;
        }
    } while(true);
    std::cout << "Enter street: ";
    std::cin.ignore();
    std::getline(std::cin, street);
    contact.setStreet(street);
    std::cout << "Enter city: ";
    std::getline(std::cin, city);
    contact.setCity(city);
    std::cout << std::endl;

    contacts[editID - 1] = contact; 

    wasContactsChanged = true;
}

void AddressBook::deleteContact(std::vector<Contact> &contacts) {
    int deleteID;
    char YN;
    do {
        std::cout << "Enter ID of contact you want to delete: ";
        std::cin >> deleteID;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number." << std::endl;
            deleteID = -1;
            continue;
        }

    } while (deleteID < 1 || deleteID > contacts.size());

    do {
        std::cout << "Are you sure you want to delete? (Y/N): ";
        std::cin >> YN;
    } while (YN != 'Y' && YN != 'N');

    if (YN == 'Y') {
        std::cout << "Contact deleted!" << std::endl;
        contacts.erase(contacts.begin() + (deleteID - 1));
    }

    wasContactsChanged = true;
}

void AddressBook::searchContact(const std::vector<Contact>& contacts) {
    std::string phrase;
    std::cout << "Enter name or phone number to search: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, phrase);

    std::vector<int> found;
    std::string phraseToLower = toLower(phrase);

    for (int i = 0; i < contacts.size(); i++) {
        if (toLower(contacts[i].getFirstName()).find(phraseToLower) != std::string::npos ||
            toLower(contacts[i].getLastName()).find(phraseToLower) != std::string::npos ||
            contacts[i].getPhoneNumber().find(phrase) != std::string::npos) {
                found.push_back(i);
            } 
    }

    if (found.empty()) {
        std::cout << "Nothing found." << std::endl;
    }

    std::cout << std::endl << "Found " << found.size() << " contacts." << std::endl << std::endl;
    AddressBook addressBook(contacts);
    for (int id : found) {
        addressBook.displayContact(contacts[id]);
    }
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
