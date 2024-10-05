#pragma once

#include <iostream>
#include <iomanip>
#include <string>

#include "Contact.h"

class PhoneBook {
  public:
    PhoneBook();

    ~PhoneBook() {}

    bool  GetInput(const std::string& prompt, std::string& input);
    bool  GetInputNumber(const std::string& prompt, int& number);
    bool  OverwriteContact(Contact& contact);
    bool  SearchContact(Contact* contacts);
    void  ReceiveCommand();
    void  DisplayContactList(Contact* contacts, int size);
    void  DisplayContactRow(Contact& contact);
    void  DisplayContactDetails(Contact& contact);

  private:
    static const int kInvalidInput = -1;
    static const int kMaxContacts = 3;
    Contact contacts_[kMaxContacts];
};
