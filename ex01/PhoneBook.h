#pragma once

#include <iostream>
#include <string>

#include "Contact.h"

class PhoneBook {
  public:
    PhoneBook() : contact_index(0) {}

    ~PhoneBook() {}

    void  OverwriteContact();

  private:
    static const int kMaxContacts = 8;
    Contact contacts_[kMaxContacts];
    int contact_index;
};
