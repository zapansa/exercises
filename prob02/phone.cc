// Christian Siquian
// CPSC 121L-01
// 10/07/23
// chrissiquian@csu.fullerton.edu
// chrissiquian
//
// Lab 9-2

#include <iostream>
#include <vector>
#include <memory>
#include "phone.h"
#include "message.h"

Phone::Phone(){}

Phone::Phone(const std::string owner_) : owner_(owner_){}

const std::string Phone::GetOwner(){ 
    return owner_; 
}

std::shared_ptr<Message> Phone::AuthorMessage(const std::string &messageref){
    Message msg = Message(messageref, owner_);
    std::shared_ptr<Message> foo = std::make_shared<Message>(messages_, owner_);
    return foo;
}

void Phone::AcceptMessage(std::shared_ptr<Message> textptr){ 
    messages_.push_back(*textptr); 
}

void Phone::PrintMessages(){ 
    // Traverse through vector messages_ -> scope Phone::
    // "for every msgiter in messages_"
    for (Message msgiter : messages_){
        std::cout << "\n";
        std::cout << msgiter.GetSender() << " : " << msgiter.GetMessage();
    }
}
