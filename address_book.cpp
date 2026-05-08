#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <limits>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::ordered_json;

class Contact {
    private:
        int id;
        std::string firstName;
        std::string lastName;
        std::string phoneNumber;
        std::string email;
        std::string street;
        std::string city;
};

class AddressBook {
    private:
        std::vector<Contact> contacts;
    public:
        void displayMenu() {
            std::cout << "===== ADDRESS BOOK =====" << std::endl;
            std::cout << "1. Add contact" << std::endl;
            std::cout << "2. Display all contacts" << std::endl;
            std::cout << "3. Edit contact" << std::endl;
            std::cout << "4. Delete contact" << std::endl;
            std::cout << "5. Search contact" << std::endl;
            std::cout << "0. Exit" << std::endl << std::endl;
        }

};

int main() {
    AddressBook addressBook;
    addressBook.displayMenu();

    return 0;
}
