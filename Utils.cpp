#include "Utils.h"

std::string Utils::getUserInputLine() {
    std::string temp;
    std::getline(std::cin >> std::ws, temp);

    return temp;
}

int Utils::getUserID(int contactSize) {
    int temp;

    do {
        std::cout << "Enter ID of contact: ";
        std::cin >> temp;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number." << std::endl;
        }
    } while (contactSize < 1 || temp > contactSize);

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
