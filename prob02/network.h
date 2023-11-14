// Please fill in below.
// <Your name>
// <Your section number> (e.g. CPSC 121L-01)
// <Date>
// <Your csu.fullerton.edu email>
// <Your GitHub username>
//
// Lab 9-2
// If it is a pair programming lab please specify partner below.
// Partner: @peteranteater

#pragma once

#include <map>
#include <memory>
#include <map>
#include <vector>

#include "message.h"
#include "phone.h"


class Network {
  public:
    void AddPhone(std::shared_ptr<Phone> phoneptr);
    void SendMessage(std::shared_ptr<Message> msgptr, const std::string recip);
    void SendMessage(std::shared_ptr<Message> msgptr, const std::vector<std::string> list_recip);

  private: 
    std::map<std::string, std::shared_ptr<Phone>> phonebook_; 
};