#include "Utils.h"

namespace Utils {
    std::string getUserInputLine() {
        std::cout << "Are you sure you want to delete? (Y/N): ";
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
}

namespace NSString {
    std::string toLower(std::string phrase) {
        for (char& c : phrase) {
            c = tolower(c);
        }

        return phrase;
    }
}



