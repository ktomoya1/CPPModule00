#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact {
  public:
    Contact(const std::string first_name, const std::string last_name, const std::string nickname, const std::string phone_number, const std::string darkest_secret)
    : first_name(first_name), last_name(last_name), nickname(nickname), phone_number(phone_number), darkest_secret(darkest_secret) {
      std::cout << "Constructor called!" << std::endl;
    };

  private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
}; 

#endif
