#include "JsonAddressBookSaver.h"

bool JsonAddressBookSaver::saveContacts(const std::vector<Contact>& contacts) {
    std::ofstream jsonFile("contacts.json");

    nlohmann::ordered_json jsonContacts = nlohmann::ordered_json::array();

    if(jsonFile.fail()) {
        return false;
    }

    for (const Contact& contact : contacts) {
        nlohmann::ordered_json j = JsonTools::to_json(contact);
        jsonContacts.push_back(j);
    }

    jsonFile << jsonContacts.dump(4);

    return true;
}
