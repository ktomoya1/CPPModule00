#include "Contact.h"

std::string Contact::GetFirstName(std::string first_name_) {
  return first_name_;
};

std::string Contact::GetLastName(std::string last_name_) {
  return last_name_;
};

std::string Contact::GetNickname(std::string nickname_) {
  return nickname_;
};

std::string Contact::GetPhoneNumber(std::string phone_number_) {
  return phone_number_;
};

std::string Contact::GetDarkestSecret(std::string darkest_secret_) {
  return darkest_secret_;
};

void Contact::SetFirstName(std::string first_name) {
  this->first_name_ = first_name;
};

void Contact::SetLastName(std::string last_name) {
  this->last_name_ = last_name;
};

void Contact::SetNickname(std::string nickname) {
  this->nickname_ = nickname;
};

void Contact::SetPhoneNumber(std::string phone_number) {
  this->phone_number_ = phone_number;
};

void Contact::SetDarkestSecret(std::string darkest_secret) {
  this->darkest_secret_ = darkest_secret;
};
