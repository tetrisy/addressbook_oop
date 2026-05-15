#include "Utils.h"

std::string Utils::getUserInput() {
    std::string temp;
    std::getline(std::cin >> std::ws, temp);

    return temp;
}

std::string NSString::toLower(std::string phrase) {
    for (char& c : phrase) {
        c = tolower(c);
    }

    return phrase;
}
