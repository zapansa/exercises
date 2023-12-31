#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "message.h"

class Phone {
  public:

    // Constructors
    Phone(const std::string owner_);

    // Acessor - Only gets phones owner, no arguments
    const std::string GetOwner();

    // Creates a Message Object whos message is the input string & (...)
    std::shared_ptr<Message> AuthorMessage(const std::string messageref);

    // Accepts message - adds message to the end of the messages_ vector 
    void AcceptMessage(std::shared_ptr<Message> text);

    // Print Messages in the message vector
    void PrintMessages();

    // get number of messages in messages_
    const int getSize(){ return messages_.size(); }

   private:
    std::string owner_;
    std::vector<std::shared_ptr<Message>> messages_;
};