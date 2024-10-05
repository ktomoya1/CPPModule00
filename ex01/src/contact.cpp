#include "Contact.h"

int Contact::GetIndex() { return this->index_; }

std::string Contact::GetFirstName() { return this->first_name_; }

std::string Contact::GetLastName() { return this->last_name_; }

std::string Contact::GetNickname() { return this->nickname_; }

std::string Contact::GetPhoneNumber() { return this->phone_number_; }

std::string Contact::GetDarkestSecret() { return this->darkest_secret_; }

void  Contact::SetIndex(const int index) {
  this->index_ = index;
}

void  Contact::SetFirstName(const std::string& first_name) {
  this->first_name_ = first_name;
}

void  Contact::SetLastName(const std::string& last_name) {
  this->last_name_ = last_name;
}

void  Contact::SetNickname(const std::string& nickname) {
  this->nickname_ = nickname;
}

void  Contact::SetPhoneNumber(const std::string& phone_number) {
  this->phone_number_ = phone_number;
}

void  Contact::SetDarkestSecret(const std::string& darkest_secret) {
  this->darkest_secret_ = darkest_secret;
}
