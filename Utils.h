#pragma once

#include <limits>
#include <iostream>

namespace Utils {
        std::string getUserInputLine();
        int getUserID(int contactSize);
        bool confirmYesNo();
};

namespace NSString {
        std::string toLower(std::string phrase);
};
