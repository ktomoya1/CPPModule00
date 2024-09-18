#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
  PhoneBook phonebook;

  while (true) {
    std::string command;

    std::cout << "Please enter a command" << std::endl;
    std::cin >> command;
    if (command == "ADD") {
      std::cout << "ADD" << std::endl;
    } else if (command == "SEARCH") {
      std::cout << "SEARCH" << std::endl;
    } else if (command == "EXIT") {
      return 0;
    } else {
      std::cout << "The valid commands are \"ADD\", \"SEARCH\" and \"EXIT\""
                << std::endl;
    }
  }
  return 0;
}
