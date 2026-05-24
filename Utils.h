#pragma once

#include <limits>
#include <iostream>

namespace Utils {
        std::string getUserInputLine();
        bool confirmDeletion();
};

namespace NSString {
        std::string toLower(std::string phrase);
};
