#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook {
  public:
    PhoneBook(const Contact contact) : contact(contact) {
      std::cout << "PhoneBook Constructor called!" << std::endl;
    }

    ~PhoneBook() {
      std::cout << "PhoneBook Destructor called!" << std::endl;
    }

  private:
    Contact contact;
};

#endif
