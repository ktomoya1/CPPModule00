#include "PhoneBook.h"

#include <iomanip>
#include <iostream>
#include <string>

PhoneBook::PhoneBook() {
  for (int i = 0; i < kMaxContacts; ++i) {
    contacts_[i].SetIndex(i);
  }
}

void PhoneBook::ReceiveCommand() {
  int write_index = 0;

  while (true) {
    std::string command;

    if (!this->GetInput("Please enter a command: ", command)) {
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
      this->DisplayContactList(this->contacts_, kMaxContacts);
      this->SearchContact(this->contacts_);
    } else if (command == "EXIT") {
      return;
    } else {
      std::cout << "The valid commands are \"ADD\", \"SEARCH\" and \"EXIT\""
                << std::endl;
    }
  }
  return;
}

bool PhoneBook::GetInput(const std::string& prompt, std::string& input) {
  std::cout << prompt;
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

bool PhoneBook::GetInputNumber(const std::string& prompt, int& number) {
  std::cout << prompt;
  int input_number;
  std::cin >> input_number;
  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input" << std::endl;
    return false;
  }
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  number = input_number;
  return true;
}

bool PhoneBook::OverwriteContact(Contact& contact) {
  std::string first_name, last_name, nickname, phone_number, darkest_secret;

  if (!this->GetInput("Please enter the first name: ", first_name)) {
    return false;
  } else if (!this->GetInput("Please enter the last name: ", last_name)) {
    return false;
  } else if (!this->GetInput("Please enter the nickname: ", nickname)) {
    return false;
  } else if (!this->GetInput("Please enter the phone number: ", phone_number)) {
    return false;
  } else if (!this->GetInput("Please enter the darkest secret: ",
                             darkest_secret)) {
    return false;
  };
  contact.SetFirstName(first_name);
  contact.SetLastName(last_name);
  contact.SetNickname(nickname);
  contact.SetPhoneNumber(phone_number);
  contact.SetDarkestSecret(darkest_secret);
  return true;
}

bool PhoneBook::SearchContact(Contact* contacts) {
  int index;
  if (!this->GetInputNumber(
          "Please enter the index of the contact you want to view: ", index))
    return false;
  this->DisplayContactDetails(contacts[index]);
  return true;
}

void PhoneBook::DisplayContactList(Contact* contacts, int size) {
  std::cout << "|     index|first name| last name|  nickname|" << std::endl;
  for (int i = 0; i < size; ++i) {
    this->DisplayContactRow(contacts[i]);
  }
  return;
}

void PhoneBook::DisplayContactRow(Contact& contact) {
  std::string trunc_first_name = contact.GetFirstName(),
              trunc_last_name = contact.GetLastName(),
              trunc_nickname = contact.GetNickname();
  if (trunc_first_name.size() > 10)
    trunc_first_name = trunc_first_name.substr(0, 9) + ".";
  if (trunc_last_name.size() > 10)
    trunc_last_name = trunc_last_name.substr(0, 9) + ".";
  if (trunc_nickname.size() > 10)
    trunc_nickname = trunc_nickname.substr(0, 9) + ".";
  std::cout << "|"
            << std::setw(10) << contact.GetIndex() << "|"
            << std::setw(10) << trunc_first_name   << "|"
            << std::setw(10) << trunc_last_name    << "|"
            << std::setw(10) << trunc_nickname     << "|"
            << std::endl;
  return;
}

void PhoneBook::DisplayContactDetails(Contact& contact) {
  std::cout << std::setw(16) << "index: " << contact.GetIndex()
            << std::endl
            << std::setw(16) << "first name: " << contact.GetFirstName()
            << std::endl
            << std::setw(16) << "last name: " << contact.GetLastName()
            << std::endl
            << std::setw(16) << "nickname: " << contact.GetNickname()
            << std::endl
            << std::setw(16) << "phone number: " << contact.GetPhoneNumber()
            << std::endl
            << std::setw(16) << "darkest Secret: " << contact.GetDarkestSecret()
            << std::endl;
  return;
}
