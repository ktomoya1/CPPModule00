#pragma once

class PhoneBook {
  public:
    PhoneBook() {}

    ~PhoneBook() {}

  private:
    static const int kMaxContacts = 8;
    Contact contacts_[kMaxContacts];
};
