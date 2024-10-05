#pragma once

#include <string>

class Contact {
  public:
    Contact() {}

    ~Contact() {}

    int         GetIndex();
    std::string GetFirstName();
    std::string GetLastName();
    std::string GetNickname();
    std::string GetPhoneNumber();
    std::string GetDarkestSecret();
    void        SetIndex(const int index);
    void        SetFirstName(const std::string& first_name);
    void        SetLastName(const std::string& last_name);
    void        SetNickname(const std::string& nickname);
    void        SetPhoneNumber(const std::string& phone_number);
    void        SetDarkestSecret(const std::string& darkest_secret);

  private:
    int index_;
    std::string first_name_;
    std::string last_name_;
    std::string nickname_;
    std::string phone_number_;
    std::string darkest_secret_;
}; 
