#include "Utils.h"

using namespace Utils;
using namespace NSString;

std::string getUserInputLine() {
    std::string temp;
    std::getline(std::cin >> std::ws, temp);

    return temp;
}

bool confirmYesNo() {
    char input;
    do {
        std::cin >> input;
    } while (!(input == 'Y' || input == 'N'));

    return input == 'Y';
}

std::string toLower(std::string phrase) {
    for (char& c : phrase) {
        c = tolower(c);
    }

    return phrase;
}
