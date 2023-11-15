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

    //The constructor is implied, implicitly created for us by the compiler. 

    // Add Phone function - void return
    void AddPhone(std::shared_ptr<Phone> phoneptr);

    // Send Message Function - Single recipient - void return
    void SendMessage(std::shared_ptr<Message> msgptr, const std::string recip);

    // Send Message Function - Overload - List recipients - void return
    void SendMessage(std::shared_ptr<Message> msgptr, const std::vector<std::string> list_recip);

  private: 
    std::map<std::string, std::shared_ptr<Phone>> phonebook_; 
};