#pragma once

#include <iostream>
#include <string>

#include "Contact.h"

class PhoneBook {
  public:
    PhoneBook() {}

    ~PhoneBook() {}

    void  ReceiveCommand();
    void  OverwriteContact();

  private:
    static const int kMaxContacts = 8;
    Contact contacts_[kMaxContacts];
};
