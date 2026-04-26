#include <iostream>
#include <vector>

struct Contact {
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string email;
    std::string street;
    std::string city;
};

Contact addContact() {
    Contact contact;
    std::cout << "==== Adding contact menu ====" << std::endl;
    std::cout << "Enter first name: ";
    std::cin >> contact.firstName;
    std::cout << "Enter last name: ";
    std::cin >> contact.lastName;
    std::cout << "Enter phone number: ";
    std::cin >> contact.phoneNumber;
    std::cout << "Enter email: ";
    std::cin >> contact.email;
    std::cout << "Enter street: ";
    std::cin >> contact.street;
    std::cout << "Enter city: ";
    std::cin >> contact.city;
    std::cout << std::endl;

    return contact;
}

void displayContact(const Contact& contact) {
    std::cout << "=== Contact information ===" << std::endl;
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
    std::cout << "5. Edit contact" << std::endl;
    std::cout << "6. Search contact" << std::endl;
    std::cout << "0. Exit" << std::endl << std::endl;
}

int getUserMenuChoice() {
    int choice;
    std::cout << "Choose option (1-6) or 0 to exit: ";
    std::cin >> choice;
    std::cout << std::endl;
    return choice;
}

int main() {
    std::vector<Contact> contacts;
    
    while(true) {
        displayMenu();
        switch(getUserMenuChoice()) {
            case 1:
                contacts.push_back(addContact());
                break;
            case 2:
                displayAllContacts(contacts);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 0:
                return 0;
            default:
                std::cout << "Unexpected input. Choose between (1-6) or 0 to exit" << std::endl;
                continue;
        }
    }

    return 0;
}

