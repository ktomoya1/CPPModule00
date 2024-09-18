#pragma once

#include <string>

class Contact {
  public:
    Contact() {}

    ~Contact() {}

    std::string GetFirstName(const std::string first_name_);
    std::string GetLastName(const std::string last_name_);
    std::string GetNickname(const std::string nickname_);
    std::string GetPhoneNumber(const std::string phone_number_);
    std::string GetDarkestSecret(const std::string darkest_secret_);

  private:
    const std::string first_name_; // クラスのデータメンバは末尾に_をつける
    const std::string last_name_;
    const std::string nickname_;
    const std::string phone_number_;
    const std::string darkest_secret_;
}; 
