#pragma once

#include <iostream>
#include <string>

#include "Contact.h"

class PhoneBook {
  public:
    PhoneBook() {}

    ~PhoneBook() {}

    void  ReceiveCommand();
    bool  OverwriteContact(Contact& contact);
    bool  GetInput(const std::string& prompt, std::string& input);

  private:
    static const int kMaxContacts = 8;
    Contact contacts_[kMaxContacts];
};
