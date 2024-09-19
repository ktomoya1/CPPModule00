#pragma once

#include <string>

class Contact {
  public:
    Contact() {}

    ~Contact() {}

    std::string GetFirstName(std::string first_name_);
    std::string GetLastName(std::string last_name_);
    std::string GetNickname(std::string nickname_);
    std::string GetPhoneNumber(std::string phone_number_);
    std::string GetDarkestSecret(std::string darkest_secret_);
    void SetFirstName(std::string first_name_);
    void SetLastName(std::string last_name_);
    void SetNickname(std::string nickname_);
    void SetPhoneNumber(std::string phone_number_);
    void SetDarkestSecret(std::string darkest_secret_);

  private:
    std::string first_name_;
    std::string last_name_;
    std::string nickname_;
    std::string phone_number_;
    std::string darkest_secret_;
}; 
