#pragma once

#include "Contact.h"


class Display {
public:
    static void displayContact(const Contact& contact);
    static void displayInvalidInputNotNumber();
    static void displayDeletionConfirmation();
    static void promptForNameOrNumber();
    static void displayNothingFound();
    static void displayHowManyFound(int amount);
};


