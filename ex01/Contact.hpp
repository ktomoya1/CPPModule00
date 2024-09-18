#pragma once

#include <string>
#include <iostream> // 確認メッセージ用

class Contact {
  public:
    Contact() {
      std::cout << "Contact Constructor called!" << std::endl;
    }

    ~Contact() {
      std::cout << "Contact Destructor called!" << std::endl;
    }

    std::string GetFirstName();
    std::string GetLastName();
    std::string GetNickname();
    std::string GetPhoneNumber();
    std::string GetDarkestSecret();

  private:
    const std::string first_name_; // クラスのデータメンバは末尾に_をつける
    const std::string last_name_;
    const std::string nickname_;
    const std::string phone_number_;
    const std::string darkest_secret_;
}; 
