#include "Utils.h"

std::string Utils::getUserInput() {
    std::string temp;
    std::getline(std::cin >> std::ws, temp);

    return temp;
}
