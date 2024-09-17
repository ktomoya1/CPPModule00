#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

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
    static const int MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
};

#endif
