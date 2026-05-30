#include "JsonAddressBookLoader.h"

std::vector<Contact> JsonAddressBookLoader::loadContacts() {
    std::ifstream jsonFile("contacts.json");

    if(!jsonFile) return {};
    
    if(jsonFile.fail()) return {};

    json jsonContacts;
    jsonFile >> jsonContacts;

    std::vector<Contact> contacts;

    for (const auto& person : jsonContacts) {
        Contact contact(person["id"], person["firstName"], person["lastName"], {person["phoneNumber"], person["email"], person["street"], person["city"]});
        contacts.push_back(contact);
    }

    return contacts;
}
