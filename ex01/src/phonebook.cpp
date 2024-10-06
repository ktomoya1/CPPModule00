#include "PhoneBook.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

PhoneBook::PhoneBook() {
  for (int i = 0; i < kMaxContacts; ++i) {
    this->contacts_[i].SetIndex(i + 1);
  }
}

void PhoneBook::ReceiveCommand() {
  int write_index = 0;

  while (true) {
    std::string command;

    if (!this->GetInput("Please enter a command: ", command)) {
      return;
    };

    if (command == "ADD") {
      if (!this->OverwriteContact(this->contacts_[write_index])) {
        return;
      }
      if (++write_index == kMaxContacts) {
        write_index = 0;
      }
    } else if (command == "SEARCH") {
      this->DisplayContactList(this->contacts_, kMaxContacts);
      if (!this->SearchContact(this->contacts_))
        return;
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
  while (true) {
    std::cout << prompt;
    if (!std::getline(std::cin, input)) {
      if (std::cin.eof()) {
        this->HandleError(kEndOfFile);
      } else {
        this->HandleError(kUnknown);
      }
      return false;
    } else if (input.empty()) {
      continue ;
    } else {
      break;
    }
  }
  return true;
}

bool PhoneBook::StringToNumber(const std::string& string, int& number) {
  std::stringstream ss(string);
  int input_number = 0;

  ss >> input_number;
  if (ss.fail()) {
    this->HandleError(kInvalidInput);
    return false;
  }
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
  std::string input_string;
  int index = 0;
  while (true) {
    if (!this->GetInput(
            "Please enter the index of the contact: ", input_string)) {
      return false;
    } else if (!StringToNumber(input_string, index)) {
      continue;
    }
    if (0 <= index && index < kMaxContacts) {
      break;
    }
    std::cout << "The index value is out of range" << std::endl;
  }
  this->DisplayContactDetails(contacts[index]);
  return true;
}

// Todo: 電子帳を書いた数だけ表示する
void PhoneBook::DisplayContactList(Contact* contacts, int size) {
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "|     index|first name| last name|  nickname|" << std::endl;
  std::cout << "---------------------------------------------" << std::endl;
  for (int i = 0; i < size; ++i) {
    this->DisplayContactRow(contacts[i]);
  }
  return;
}

void PhoneBook::DisplayContactRow(Contact& contact) {
  std::string trunc_first_name = this->TruncateField(contact.GetFirstName(), kFieldWidth),
              trunc_last_name = this->TruncateField(contact.GetLastName(), kFieldWidth),
              trunc_nickname = this->TruncateField(contact.GetNickname(), kFieldWidth);
  std::cout << "|"
            << std::setw(10) << contact.GetIndex() << "|"
            << std::setw(10) << trunc_first_name   << "|"
            << std::setw(10) << trunc_last_name    << "|"
            << std::setw(10) << trunc_nickname     << "|"
            << std::endl;
  return;
}

std::string PhoneBook::TruncateField(const std::string& field, std::string::size_type width) {
  return (field.size() > width) ? field.substr(0, width - 1) + "."
                                : field;
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

void PhoneBook::HandleError(ErrorCode code) {
  switch (code) {
    case kSuccess:
      break;
    case kEndOfFile:
      std::cout << "\n" << "EOF reached" << std::endl;
      break;
    case kInvalidInput:
      std::cout << "Invalid input" << std::endl;
      break;
    default:
      std::cerr << "Failed to input" << std::endl;
      break;
  }
  return;
}
