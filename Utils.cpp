#include "Utils.h"

namespace Utils {
    std::string getUserInputLine() {
        std::string temp;
        std::getline(std::cin >> std::ws, temp);

        return temp;
    }

    int getUserID(int contactSize) {
    int id;

    do {
        std::cout << "Enter ID of contact: ";
        std::cin >> id;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number." << std::endl;
        }
    } while (contactSize < 1 || id > contactSize);

    return id;
}


    bool confirmDeletion() {
        std::cout << "Are you sure you want to delete? (Y/N): ";
        char input;
        do {
            std::cin >> input;
        } while (!(input == 'Y' || input == 'N'));  

        return input == 'Y';
    }

    
};

namespace JsonTools {
    nlohmann::ordered_json to_json(const Contact& contact) {
        nlohmann::ordered_json j = nlohmann::ordered_json{
            {"id", contact.getID()},
            {"firstName", contact.getFirstName()},
            {"lastName", contact.getLastName()},
            {"phoneNumber", contact.getPhoneNumber()},
            {"email", contact.getEmail()},
            {"street", contact.getStreet()},
            {"city", contact.getCity()}
        };
        return j;
    }
};

namespace NSString {
    std::string toLower(std::string phrase) {
        for (char& c : phrase) {
            c = tolower(c);
        }

        return phrase;
    }
};



