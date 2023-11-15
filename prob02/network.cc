#include <iostream>
#include <vector>
#include "network.h"
#include "phone.h"

/*
    Create a function `AddPhone` that accepts a `std::shared_ptr` to a `Phone` and 
    inserts that `Phone` to the `phonebook_`. The key is the name of that phone's 
    owner, and the value is the shared pointer to the `Phone`.
*/
void Network::AddPhone(std::shared_ptr<Phone> phoneptr) {
    // Reference the object from pointer
    Phone phoneobj = *phoneptr;

    // Insert the referenced object into the phonebook 
    /* NOTE: 
        Emplace - Constructs, whereas 
        Insert - Copies 
        
        phonebook_.emplace(phoneobj.GetOwner(), phoneptr);
    */
    phonebook_.insert({phoneobj.GetOwner(), phoneptr});
}

/*
    Create a function `SendMessage` that accepts a `std::shared_ptr` to a `Message` and a 
    `const` reference to a `std::string` representing the intended recipient of this 
    message. **You must check** if the intended recipient is in the `phonebook_`, because 
    if an invalid recipient is provided, no message should be sent over the network. If 
    the recipient exists in the `phonebook_`, then use the `Phone::AcceptMessage` function 
    to send that message to the recipient's phone.
*/
void Network::SendMessage(std::shared_ptr<Message> msgptr, const std::string recip) {
    // Check if recipient exists in the network 
    if (phonebook_.count(recip) > 0){
        phonebook_.at(recip)->AcceptMessage(msgptr);
    }
    else {
        std::cout << "Cannot send the message: " << msgptr->GetMessage() << "\n";
        std::cout << recip << " does Not exist!\n\n";
    }
}

/*
    Create a function `SendMessage` that accepts a `std::shared_ptr` to a `Message` and a 
    `const` reference to a vector of `std::string` representing a list of recipients in the 
    network to send the given message to. Like above, **you must check** if the intended 
    recipient is in the `phonebook_` before sending the message to that recipient's phone.
*/
void Network::SendMessage(std::shared_ptr<Message> msgptr, const std::vector<std::string> list_recip) {
    // check the list of every recipient
    for (std::string recip : list_recip){    
        // Check if recipient exists in the network
        if (phonebook_.count(recip) > 0){
            Phone recip_phone = *phonebook_.at(recip);
            recip_phone.AcceptMessage(msgptr);
        }
        else{
            std::cout << "Cannot send the message: " << msgptr->GetMessage() << "\n";
            std::cout << recip << " does Not exist!\n\n";
        }
    }

}