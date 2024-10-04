#include <iostream>
#include <string>

#include "PhoneBook.h"

void PhoneBook::ReceiveCommand() {
  while (true) {
    std::string command;
    int write_index = 0;

    if (!this->GetInput("Please enter a command", command)) {
      return;
    };

    if (command.empty()) {
      continue;
    } else if (command == "ADD") {
      if (!this->OverwriteContact(this->contacts_[write_index])) {
        return;
      }
      if (++write_index == kMaxContacts) {
        write_index = 0;
      }
    } else if (command == "SEARCH") {
      std::cout << "SEARCH" << std::endl;
    } else if (command == "EXIT") {
      return;
    } else {
      std::cout << "The valid commands are \"ADD\", \"SEARCH\" and \"EXIT\""
                << std::endl;
    }
  }
  return;
}

// contactにフィールドを設定
bool PhoneBook::OverwriteContact(Contact& contact) {
  std::string first_name, last_name, nickname, phone_number, darkest_secret;
  // 入力を取得
  if (!this->GetInput("Please enter the first name", first_name)) {
    return false;
  } else if (!this->GetInput("Please enter the last name", last_name)) {
    return false;
  } else if (!this->GetInput("Please enter the nickname", nickname)) {
    return false;
  } else if (!this->GetInput("Please enter the phone number", phone_number)) {
    return false;
  } else if (!this->GetInput("Please enter the darkest secret", darkest_secret)) {
    return false;
  };
  // setterメソッドを使う
  contact.SetFirstName(first_name);
  contact.SetLastName(last_name);
  contact.SetNickname(nickname);
  contact.SetPhoneNumber(phone_number);
  contact.SetDarkestSecret(darkest_secret);
  return true;
}

bool  PhoneBook::GetInput(const std::string& prompt, std::string& input) {
  std::cout << prompt << std::endl;
  if (!std::getline(std::cin, input)) {
    if (std::cin.eof()) {
      std::cerr << "EOF received" << std::endl;
    } else {
      std::cerr << "Failed to input" << std::endl;
    }
    return false;
  }
  return true;
}
