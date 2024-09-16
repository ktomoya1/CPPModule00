#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream> // 確認メッセージ用

class Contact {
  public:
    explicit Contact(const std::string& first_name, const std::string& last_name, const std::string& nickname, const std::string& phone_number, const std::string& darkest_secret)
    : first_name(first_name), last_name(last_name), nickname(nickname), phone_number(phone_number), darkest_secret(darkest_secret) {
      std::cout << "Constructor called!" << std::endl;
    }

    ~Contact() {
      std::cout << "Destructor called!" << std::endl;
    }

  private:
    const std::string first_name;
    const std::string last_name;
    const std::string nickname;
    const std::string phone_number;
    const std::string darkest_secret;
}; 

#endif
