#include <iostream>
#include <vector>
#include <memory>
#include "phone.h"
#include "message.h"

/* Non-default constructor */  
Phone::Phone(const std::string owner_) : owner_(owner_){}

/* Accessor to get owner */ 
const std::string Phone::GetOwner(){ 
    return owner_; 
}

/*
    Create a member function `AuthorMessage`, which accepts a `const` reference 
    to a string, and returns a `std::shared_ptr<Message>`. This function creates 
    a `Message` object whose message is set to the input string, and whose sender 
    is set to the name of this phone's owner.
*/
std::shared_ptr<Message> Phone::AuthorMessage(const std::string messageref){
    // Create message object 
    Message msg = Message(messageref, owner_);
    // Create a pointer for the message
    std::shared_ptr<Message> msg_ptr = std::make_shared<Message>(msg);
    // Return pointer as type
    return msg_ptr;
}

/*
    Create a member function `AcceptMessage`, which accepts a 
    `std::shared_ptr<Message>` and adds that message to the **end** of the 
    `messages_` vector.
*/
void Phone::AcceptMessage(std::shared_ptr<Message> text_ptr){ 
    // This can be .push_back since the return value is just void, insert otherwise
    messages_.push_back(text_ptr); 
}

/*
    Create a member function called `PrintMessages` that returns `void` and does 
    not take in any parameters. This function should iterate through all the 
    messages sent to this phone, and print each message on a new line, in the 
    format `"sender: message"`
*/
void Phone::PrintMessages(){ 
    // Traverse through vector messages_ -> scope Phone::
    // "for every msgiter in messages_"
    for (std::shared_ptr<Message> msg_ptr_iter : messages_)
    {
        std::cout << "\n";
        std::cout << msg_ptr_iter->GetSender() << ": " << msg_ptr_iter->GetMessage();
    }
}
