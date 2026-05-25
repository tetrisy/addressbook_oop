#pragma once

#include "Contact.h"
#include <nlohmann/json.hpp>
#include <iostream>

namespace Utils {
    std::string getUserInputLine();
    int getUserID(int contactSize);
    bool confirmDeletion();
    nlohmann::ordered_json to_json(const Contact& contact);
};

namespace NSString {
    std::string toLower(std::string phrase);
};
