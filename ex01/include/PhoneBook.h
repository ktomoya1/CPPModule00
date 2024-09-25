#pragma once

#include "Contact.h"

class PhoneBook {
  public:
    PhoneBook() {}

    ~PhoneBook() {}

    void  ReceiveCommand();
    void  OverwriteContact(Contact& contact);

  private:
    static const int kMaxContacts = 8;
    Contact contacts_[kMaxContacts];
};
