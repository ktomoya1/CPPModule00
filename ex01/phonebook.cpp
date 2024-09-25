#include "PhoneBook.h"

void  PhoneBook::ReceiveCommand() {
  while (true) {
    std::string command;
    int         write_index = 0;

    std::cout << "Please enter a command" << std::endl;
    if (std::getline(std::cin, command) == false) {
      std::cout << "EOF received" << std::endl;
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

void  PhoneBook::OverwriteContact(Contact& contact) {
  std::string line;

  std::cout << "Please enter the first name" << std::endl;
  std::getline(std::cin, line);
  contact.SetFirstName(line);
  return;
}
