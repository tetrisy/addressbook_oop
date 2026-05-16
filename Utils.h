#pragma once

#include <limits>
#include <iostream>

namespace Utils {
        std::string getUserInput();
        int getUserID(int contactSize);
        bool confirmYesNo();
};

namespace NSString {
        std::string toLower(std::string phrase);
};
