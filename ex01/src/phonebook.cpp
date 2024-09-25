#include "PhoneBook.h"

#include <iostream>

void PhoneBook::ReceiveCommand() {
  while (true) {
    std::string command;
    int write_index = 0;

    std::cout << "Please enter a command" << std::endl;
    if (std::getline(std::cin, command) == false) {
      std::cerr << "EOF received" << std::endl;
      return;
    }
    if (command == "ADD") {
      this->OverwriteContact(this->contacts_[write_index]);
      if (++write_index == kMaxContacts) {
        write_index = 0;
      }
    } else if (command == "SEARCH") {
      std::cout << "SEARCH" << std::endl;
    } else if (command == "EXIT") {
      return;
    } else if (command.empty()) {
      continue;
    } else {
      std::cout << "The valid commands are \"ADD\", \"SEARCH\" and \"EXIT\""
                << std::endl;
    }
  }
  return;
}

void PhoneBook::OverwriteContact(Contact& contact) {
  std::string line;
  Contact::Field field = Contact::kFirstName;

  while (true) {
    switch (field) {
      case Contact::kFirstName:
        std::cout << "Please enter the first name" << std::endl;
        std::getline(std::cin, line);
        contact.SetFirstName(line);
        field = Contact::kLastName;
      case Contact::kLastName:
        std::cout << "Please enter the last name" << std::endl;
        std::getline(std::cin, line);
        contact.SetLastName(line);
        field = Contact::kNickname;
      case Contact::kNickname:
        std::cout << "Please enter the nickname" << std::endl;
        std::getline(std::cin, line);
        contact.SetNickname(line);
        field = Contact::kPhoneNumber;
      case Contact::kPhoneNumber:
        std::cout << "Please enter the phone number" << std::endl;
        std::getline(std::cin, line);
        contact.SetPhoneNumber(line);
        field = Contact::kDarkestSecret;
      case Contact::kDarkestSecret:
        std::cout << "Please enter the darkest secret" << std::endl;
        std::getline(std::cin, line);
        contact.SetDarkestSecret(line);
        return;
    }
  }
  return;
}
