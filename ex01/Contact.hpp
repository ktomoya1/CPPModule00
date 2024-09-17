#ifndef CONTACT_HPP
#define CONTACT_HPP

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

  private:
    const std::string first_name;
    const std::string last_name;
    const std::string nickname;
    const std::string phone_number;
    const std::string darkest_secret;
}; 

#endif
