#include "JsonAddressBookLoader.h"

std::vector<Contact> JsonAddressBookLoader::loadContacts(std::istream& fileStream) {
    if(fileStream.fail()) return {};

    json jsonContacts;
    fileStream >> jsonContacts;

    std::vector<Contact> contacts;

    for (const auto& person : jsonContacts) {
        Contact contact(person["id"], person["firstName"], person["lastName"], {person["phoneNumber"], person["email"], person["street"], person["city"]});
        contacts.push_back(contact);
    }

    return contacts;
}
