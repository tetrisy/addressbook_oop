#pragma once

#include <vector>

class IAddressBookSaver {
public:
    virtual bool saveContacts(const std::vector<Contact>& contacts, const std::string& fileName) = 0;    
};
