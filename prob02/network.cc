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

#include <iostream>
#include <vector>
#include "network.h"
#include "phone.h"

void Network::AddPhone(std::shared_ptr<Phone> phoneptr) {
    // Reference the object from pointer
    Phone phoneobj = *phoneptr;

    // Insert the referenced object into the phonebook 
    /* NOTE: 
        Emplace - Constructs, whereas 
        Insert - Copies 
    */
    // phonebook_.emplace(phoneobj.GetOwner(), phoneptr);
    phonebook_.insert({phoneobj.GetOwner(), phoneptr});
}

void Network::SendMessage(std::shared_ptr<Message> msgptr, const std::string recip) {
    // Check if recipient exists in the network 
    if (phonebook_.count(recip) > 0){
        Phone phone; 
        phone.AcceptMessage(msgptr);
    }
    else {
        // Does not exist, print an error
    }
}

void Network::SendMessage(std::shared_ptr<Message> msgptr, const std::vector<std::string> list_recip) {
    // check the list of every recipient
    for (std::string recip : list_recip){    
        // Check if recipient exists in the network
        if (phonebook_.count(recip) > 0){
            Phone phone;
            phone.AcceptMessage(msgptr);
        }
        else{
            // Does not exist, print an error
        }
    }

}