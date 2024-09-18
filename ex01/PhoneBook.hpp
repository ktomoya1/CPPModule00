#pragma once

#include <iostream>

class PhoneBook {
  public:
    PhoneBook() {
      std::cout << "PhoneBook Constructor called!" << std::endl;
    }

    ~PhoneBook() {
      std::cout << "PhoneBook Destructor called!" << std::endl;
    }

  private:
    static const int kMaxContacts = 8;
    Contact contacts_[kMaxContacts];
};
