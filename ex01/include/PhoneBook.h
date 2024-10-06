#pragma once

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Contact.h"

class PhoneBook {
  public:
    enum ErrorCode {
      kSuccess = 0,
      kEndOfFile,
      kInvalidInput,
      kUnknown,
    };

    PhoneBook();

    ~PhoneBook() {}

    bool  GetInput(const std::string& prompt, std::string& input);
    bool  StringToNumber(const std::string& prompt, int& number);
    bool  OverwriteContact(Contact& contact);
    bool  SearchContact(Contact* contacts);
    bool  DisplayContactList(Contact* contacts);
    void  ReceiveCommand();
    void  DisplayContactRow(Contact& contact);
    void  DisplayContactDetails(Contact& contact);
    void  HandleError(ErrorCode code);
    void  AddContactCount();
    int   GetContactCount();
    std::string TruncateField(const std::string& field, std::string::size_type width);

  private:
    static const int kMaxContacts = 8;
    static const int kFieldWidth = 10;
    int     contact_count_;
    Contact contacts_[kMaxContacts];
};
