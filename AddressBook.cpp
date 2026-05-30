#include "AddressBook.h"

using json = nlohmann::ordered_json;

void AddressBook::loadContacts(IAddressBookLoader& load) {

    m_contacts = load.loadContacts();
}

bool AddressBook::saveContacts(std::ostream& fileStream) {
    nlohmann::ordered_json jsonContacts = nlohmann::ordered_json::array();

    if(fileStream.fail()) {
        return false;
    }

    for (const Contact& contact : m_contacts) {
        nlohmann::ordered_json j = Utils::to_json(contact);
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
    editID = Utils::getUserID(m_contacts.size());

    if(editID > 0 && editID <= m_contacts.size()) {
        m_contacts[editID - 1].editDetails();
    }

    wasAnyContactsChanged = true;
}

void AddressBook::deleteContact() {
    int deleteID;
    char YN;
    do {
        deleteID = Utils::getUserID(m_contacts.size());

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Display::displayInvalidInputNotNumber();
            deleteID = -1;
        }

    } while (deleteID < 1 || deleteID > m_contacts.size());

    if (Utils::confirmDeletion()) {
        Display::displayDeletionConfirmation();
        m_contacts.erase(m_contacts.begin() + (deleteID - 1));
    }

    wasAnyContactsChanged = true;
}

std::vector<int> AddressBook::searchContact() {
    std::string phrase;
    Display::promptForNameOrNumber();
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
        Display::displayNothingFound();
    } else {
        Display::displayHowManyFound(found.size());
    }

    return found;
}

void AddressBook::displayAllContacts() {
    for(const Contact& contact : m_contacts) {
        Display::displayContact(contact);
    }
}



