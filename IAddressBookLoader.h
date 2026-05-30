#pragma once

#include "Contact.h"
#include <vector>

class IAddressBookLoader {
public:
    virtual std::vector<Contact> loadContacts() = 0;    
};
