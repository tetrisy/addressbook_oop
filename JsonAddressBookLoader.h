#pragma once

#include "IAddressBookLoader.h"
#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::ordered_json;

class JsonAddressBookLoader : public IAddressBookLoader {
public:
    std::vector<Contact> loadContacts() override;
};
