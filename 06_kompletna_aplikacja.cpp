#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <limits>
#include <fstream>

struct Contact {
    int id = 0;
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string email;
    std::string street;
    std::string city;
};

void saveContacts(std::vector<Contact> &contacts) {
    std::ofstream file("contacts.json");

    if (!file.is_open()) {
        std::cout << "Error! Couldn't open file!" << std::endl;
        return;
    }

    file.close();
}

bool emailValidation(std::string email) {
    const std::regex emailReg(R"([a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

    if(std::regex_match(email, emailReg)) {
        return true;
    } else {
        std::cout << "Invalid email! Enter a valid email address." << std::endl;
        return false;
    }
}

bool phoneNumberValidation(std::string phoneNumber) {
    const std::regex phoneReg("^\\d{9}$");
    
    if(std::regex_match(phoneNumber, phoneReg)) {
        return true;
    } else {
        std::cout << "Invalid phone number! Enter a valid phone number." << std::endl;
        return false;
    }
}

Contact addContact() {
    Contact contact;
    std::cout << "==== Adding contact menu ====" << std::endl; 
    std::cout << "Enter first name: ";
    std::cin.ignore();
    std::getline(std::cin, contact.firstName); 
    std::cout << "Enter last name: ";
    std::getline(std::cin, contact.lastName);
    do {
        std::cout << "Enter phone number: ";
        std::cin >> contact.phoneNumber;
    } while(!phoneNumberValidation(contact.phoneNumber));
    do {
        std::cout << "Enter email: ";
        std::cin >> contact.email;
    } while(!emailValidation(contact.email));
    std::cout << "Enter street: ";
    std::cin.ignore();
    std::getline(std::cin, contact.street);
    std::cout << "Enter city: ";
    std::getline(std::cin, contact.city);
    std::cout << std::endl;

    contact.id++;

    return contact;
}

void editContact(std::vector<Contact> &contacts) {
    int editID;
    do {
        std::cout << "Enter ID of contact you want to edit: ";
        std::cin >> editID;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number." << std::endl;
            editID = -1;
            continue;
        }

    } while (editID < 1 || editID > contacts.size());
    
    std::cout << "Enter first name: ";
    std::cin.ignore();
    std::getline(std::cin, contacts[editID - 1].firstName); 
    std::cout << "Enter last name: ";
    std::getline(std::cin, contacts[editID - 1].lastName);
    do {
        std::cout << "Enter phone number: ";
        std::cin >> contacts[editID - 1].phoneNumber;
    } while(!phoneNumberValidation(contacts[editID - 1].phoneNumber));
    do {
        std::cout << "Enter email: ";
        std::cin >> contacts[editID - 1].email;
    } while(!emailValidation(contacts[editID - 1].email));
    std::cout << "Enter street: ";
    std::cin.ignore();
    std::getline(std::cin, contacts[editID - 1].street);
    std::cout << "Enter city: ";
    std::getline(std::cin, contacts[editID - 1].city);
    std::cout << std::endl;
}

void deleteContact(std::vector<Contact> &contacts) {
    int deleteID;
    char YN;
    do {
        std::cout << "Enter ID of contact you want to delete: ";
        std::cin >> deleteID;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number." << std::endl;
            deleteID = -1;
            continue;
        }

    } while (deleteID < 1 || deleteID > contacts.size());

    do {
        std::cout << "Are you sure you want to delete? (Y/N): ";
        std::cin >> YN;
    } while (YN != 'Y' && YN != 'N');

    if (YN == 'Y') {
        std::cout << "Contact deleted!" << std::endl;
    } else {
        return;
    }
}

void displayContact(const Contact& contact) {
    std::cout << "=== Contact information ===" << std::endl;
    std::cout << "ID: " << contact.id << std::endl;
    std::cout << "Frist Name: " << contact.firstName << std::endl;
    std::cout << "Last Name: " << contact.lastName << std::endl;
    std::cout << "Phone Number: " << contact.phoneNumber << std::endl;
    std::cout << "Email: " << contact.email << std::endl;
    std::cout << "Street: " << contact.street << std::endl;
    std::cout << "City: " << contact.city << std::endl << std::endl;
}

void displayAllContacts(std::vector<Contact> &contacts) {
    for(Contact contact : contacts) {
        displayContact(contact);
    }
}

void displayMenu() {
    std::cout << "===== ADDRESS BOOK =====" << std::endl;
    std::cout << "1. Add contact" << std::endl;
    std::cout << "2. Display all contacts" << std::endl;
    std::cout << "3. Edit contact" << std::endl;
    std::cout << "4. Delete contact" << std::endl;
    std::cout << "5. Search contact" << std::endl;
    std::cout << "0. Exit" << std::endl << std::endl;
}

int getUserMenuChoice() {
    int choice;
    do {
        std::cout << "Choose option (1-5) or 0 to exit: ";
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number." << std::endl;
            choice = -1;
            continue;
        }
    } while (choice < 0 || choice > 5);
    std::cout << std::endl;
    return choice;
}

bool executeMenuOption(std::vector<Contact> &contacts) {
    switch(getUserMenuChoice()) {
        case 1:
            contacts.push_back(addContact());
            break;
        case 2:
            displayAllContacts(contacts);
            break;
        case 3:
            editContact(contacts);
            break;
        case 4:
            deleteContact(contacts);
            break;
        case 5:
            break;
        case 0:
            return false;
        default:
            std::cout << "Unexpected input. Choose between (1-6) or 0 to exit" << std::endl;
            break;
    }
    return true;
}

int main() {
    std::vector<Contact> contacts;
    bool isWorking = true;

    while(isWorking) {
        displayMenu();
        isWorking = executeMenuOption(contacts);
    }

    return 0;
}

