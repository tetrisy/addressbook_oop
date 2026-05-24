#include "AddressBook.h"
#include "Contact.h"
#include "Display.h"
#include "Utils.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using json = nlohmann::ordered_json;

bool AddressBook::loadContacts(std::istream& fileStream) {

    if(fileStream.fail()) {
        return false;
    }

    json jsonContacts;
    fileStream >> jsonContacts;

    for (const auto& person : jsonContacts) {
        Contact contact(person["id"], person["firstName"], person["lastName"], {person["phoneNumber"], person["email"], person["street"], person["city"]});
        m_contacts.push_back(contact);
    }

    return true;
}

bool AddressBook::saveContacts(std::ostream& fileStream) {
    nlohmann::ordered_json jsonContacts = nlohmann::ordered_json::array();

    if(fileStream.fail()) {
        return false;
    }

    for (const Contact& contact : m_contacts) {
        json j;
        AddressBook::to_json(j, contact);
        jsonContacts.push_back(j);
    }

    fileStream << jsonContacts.dump(4);

    return true;
}

void AddressBook::createContact() {
    Contact contact = Contact::getContactDetailsFromUser();
    contact.setID(m_contacts.size() + 1);

    wasAnyContactsChanged = true;

    m_contacts.push_back(contact);
}

void AddressBook::editContact() {
    int editID;
    editID = AddressBook::getUserID(m_contacts.size());

    if(editID > 0 && editID <= m_contacts.size()) {
        m_contacts[editID - 1].editDetails();
    }

    wasAnyContactsChanged = true;
}

void AddressBook::deleteContact() {
    int deleteID;
    char YN;
    do {
        deleteID = AddressBook::getUserID(m_contacts.size());

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number." << std::endl;
            deleteID = -1;
        }

    } while (deleteID < 1 || deleteID > m_contacts.size());

    if (Utils::confirmDeletion()) {
        std::cout << "Contact deleted!" << std::endl;
        m_contacts.erase(m_contacts.begin() + (deleteID - 1));
    }

    wasAnyContactsChanged = true;
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
        Display::displayContact(contact);
    }
}



int AddressBook::getUserID(int contactSize) {
    int id;

    do {
        std::cout << "Enter ID of contact: ";
        std::cin >> id;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number." << std::endl;
        }
    } while (contactSize < 1 || id > contactSize);

    return id;
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
