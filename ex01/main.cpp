#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
  Contact contact("Tomoya", "Kudo", "ktomoya", "070-3960-6898", "None");
  PhoneBook phonebook(contact);
  return 0;
}
