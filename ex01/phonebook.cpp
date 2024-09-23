#include "PhoneBook.h"

void  PhoneBook::ReceiveCommand() {
  while (true) {
    std::string command;

    std::cout << "Please enter a command" << std::endl;
    if (std::getline(std::cin, command) == false) {
      std::cout << "EOF received" << std::endl;
      return;
    }
    if (command == "ADD") {
      this->OverwriteContact();
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

void  PhoneBook::OverwriteContact() {
  std::string line;

  std::cout << "Please enter the first name" << std::endl;
  std::getline(std::cin, line);
  // 2. index番のcontactsの値を変更する
  // 3. indexをインクリメントする&必要ならば0に初期化する
  return;
}
