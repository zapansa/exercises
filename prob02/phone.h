// Christian Siquian
// CPSC 121L-01
// 10/07/23
// chrissiquian@csu.fullerton.edu
// chrissiquian
//
// Lab 9-2

#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "message.h"

class Phone {
  public:
    Phone();
    Phone(const std::string owner_);
    void GetOwner(std::string owner_);
    std::shared_ptr<Message> AuthorMessage(const std::string& messageref);
    void AcceptMessage(std::shared_ptr<Message> text);
    void PrintMessages();

   private:
    std::string owner_;
    std::vector<Message> messages_;
  // ======================= YOUR CODE HERE =======================
  // Write the Phone class here. Refer to the README for the member
  // variables, constructors, and member functions needed.
  //
  // Select one among you and your lab partner to be the "driver"
  // and the other to be the "navigator". The driver should write
  // the code, while the navigator reviews the code. Both of you
  // should communicate and share thoughts as you go along.
  // ===============================================================
};