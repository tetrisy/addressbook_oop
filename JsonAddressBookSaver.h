#pragma once

#include "Contact.h"
#include "IAddressBookSaver.h"
#include "Utils.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <vector>

using json = nlohmann::ordered_json;

class JsonAddressBookSaver : public IAddressBookSaver {
public:
    bool saveContacts(const std::vector<Contact>& contacts, const std::string& fileName) override;
};
