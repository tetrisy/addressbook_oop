#include "AddressBook.h"
#include "Contact.h"
#include <iostream>
// #include <string>
// #include <vector>
// #include <regex>
// #include <limits>
// #include <fstream>
// #include <nlohmann/json.hpp>
// using json = nlohmann::ordered_json;

int main() {
    AddressBook addressBook(addressBook.loadContacts());
    addressBook.displayMenu();

    return 0;
}
