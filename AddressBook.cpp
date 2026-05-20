#include "AddressBook.h"
#include "Contact.h"
#include "Utils.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using json = nlohmann::ordered_json;

void AddressBook::loadContacts() {
    std::ifstream file ("contacts.json");

    if(file.fail()) {
        std::cout << "Error! File couldn't be opened." << std::endl;
        return;
    }

    if (!file.is_open()) {
        std::cout << "No contacts to load." << std::endl;
        return;
    }

    json jsonContacts;
    file >> jsonContacts;

    for (const auto& person : jsonContacts) {
        Contact contact(person["id"], person["firstName"], person["lastName"], {person["phoneNumber"], person["email"], person["street"], person["city"]});
        m_contacts.push_back(contact);
    }

    std::cout << "Loaded " << m_contacts.size() << " contacts!" << std::endl << std::endl;
}

void AddressBook::saveContacts() {
    nlohmann::ordered_json jsonContacts = nlohmann::ordered_json::array();

    std::ofstream file("contacts.json");
    if(file.fail()) {
        std::cout << "Error! File couldn't be opened." << std::endl;
        return;
    }

    for (const Contact& contact : m_contacts) {
        json j;
        AddressBook::to_json(j, contact);
        jsonContacts.push_back(j);
    }

    file << jsonContacts.dump(4);
}

void AddressBook::createContact() {
    std::cout << "==== Adding contact menu ====" << std::endl; 
    Contact contact = Contact::getContactDetailsFromUser();
    contact.setID(m_contacts.size() + 1);

    wasContactsChanged = true;

    m_contacts.push_back(contact);
}

void AddressBook::editContact() {
    int editID;
    int contactSize = m_contacts.size();
    editID = AddressBook::getUserID(contactSize);

    Contact contact = Contact::getContactDetailsFromUser();
    contact.setID(m_contacts[editID - 1].getID());

    m_contacts[editID - 1] = contact; 

    wasContactsChanged = true;
}

void AddressBook::deleteContact() {
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
        }

    } while (deleteID < 1 || deleteID > m_contacts.size());

    bool deleteConfirmed = false;

    std::cout << "Are you sure you want to delete? (Y/N): ";
    deleteConfirmed = Utils::confirmYesNo();

    if (deleteConfirmed) {
        std::cout << "Contact deleted!" << std::endl;
        m_contacts.erase(m_contacts.begin() + (deleteID - 1));
    }

    wasContactsChanged = true;
}

std::vector<int> AddressBook::searchContact() {
    std::string phrase;
    std::cout << "Enter name or phone number to search: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, phrase);

    std::vector<int> found;
    std::string phraseToLower = NSString::toLower(phrase);

    for (int i = 0; i < m_contacts.size(); i++) {
        if (NSString::toLower(m_contacts[i].getFirstName()).find(phraseToLower) != std::string::npos ||
            NSString::toLower(m_contacts[i].getLastName()).find(phraseToLower) != std::string::npos ||
            m_contacts[i].getPhoneNumber().find(phrase) != std::string::npos) {
                found.push_back(i);
            } 
    }

    if (found.empty()) {
        std::cout << "Nothing found." << std::endl;
    }

    std::cout << std::endl << "Found " << found.size() << " contacts." << std::endl << std::endl;

    return found;
}

void AddressBook::displayAllContacts() {
    for(const Contact& contact : m_contacts) {
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

int AddressBook::getUserID(int contactSize) {
    int temp;

    do {
        std::cout << "Enter ID of contact: ";
        std::cin >> temp;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number." << std::endl;
        }
    } while (contactSize < 1 || temp > contactSize);

    return temp;
}

void AddressBook::to_json(nlohmann::ordered_json& j, const Contact& contact) {
    j = nlohmann::ordered_json{ {"id", contact.getID()}, 
            {"firstName", contact.getFirstName()}, 
            {"lastName", contact.getLastName()}, 
            {"phoneNumber", contact.getPhoneNumber()}, 
            {"email", contact.getEmail()}, 
            {"street", contact.getStreet()}, 
            {"city", contact.getCity()} };
}
