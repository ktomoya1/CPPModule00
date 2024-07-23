#include <iostream>

void to_uppercase(std::string &str)
{
  for (std::string::size_type i = 0; i < str.size(); ++i)
    str[i] = std::toupper(static_cast<unsigned char>(str[i]));
}

int main(int argc, char* argv[]) {
  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  else {
    for (int i = 1; i < argc; ++i) {
      std::string arg = argv[i];
      to_uppercase(arg);
      std::cout << arg;
    }
  }
  std::cout << std::endl;
  return 0;
}
