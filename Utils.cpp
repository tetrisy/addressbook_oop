#include "Utils.h"

using namespace Utils;
using namespace NSString;

std::string Utils::getUserInputLine() {
    std::string temp;
    std::getline(std::cin >> std::ws, temp);

    return temp;
}

bool Utils::confirmYesNo() {
    char input;
    do {
        std::cin >> input;
    } while (!(input == 'Y' || input == 'N'));

    return input == 'Y';
}

std::string NSString::toLower(std::string phrase) {
    for (char& c : phrase) {
        c = tolower(c);
    }

    return phrase;
}
