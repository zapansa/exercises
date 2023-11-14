// Christian Siquian
// CPSC 121L-01
// 10/07/23
// chrissiquian@csu.fullerton.edu
// chrissiquian
//
// Lab 9-2

#include <iostream>
#include <memory>

#include "network.h"
#include "phone.h"
 
int main() {
  Network csuf_network;
  // =================== YOUR CODE HERE ===================
  // 1. Create 3 objects of type `std::shared_ptr<Phone>`.
  //    `phone1`: a pointer to a Phone owned by Anna
  //    `phone2`: a pointer to a Phone owned by Raf
  //    `phone3`: a pointer to a Phone owned by JC
  // ======================================================
  std::shared_ptr<Phone> phone1 = std::make_shared<Phone>();
  std::shared_ptr<Phone> phone2 = std::make_shared<Phone>();
  std::shared_ptr<Phone> phone3 = std::make_shared<Phone>();
  // =================== YOUR CODE HERE ===================
  // 2. Add each phone to the Network, `csuf_network`.
  // ======================================================

  // =================== YOUR CODE HERE ===================
  // 3. Send the message "Sup" to Raf over the network,
  //    authored on Anna's phone.
  // ======================================================

  // =================== YOUR CODE HERE ===================
  // 4. Send the message "Lol" to Anna over the network,
  //    authored on Raf's phone.
  // ======================================================

  // =================== YOUR CODE HERE ===================
  // 5. Create a vector of strings containing "Anna" and
  //    "Raf" called `jcs_class`. Call the SendMessage
  //     overload to author a message on JC's phone and send
  //     the message "Hi class!" to everyone in `jcs_class`.
  // ======================================================

  // =================== YOUR CODE HERE ===================
  // 6. Send the message "Hi Prof!" to JC over the network,
  //    authored on Anna's phone.
  // ======================================================

  // =================== YOUR CODE HERE ===================
  // 7. Send the message "help how do C++" to JC over the
  //    network, authored on Raf's phone.
  // ======================================================

  // =================== YOUR CODE HERE ===================
  // 8. Complete the std::cout statements below to display
  //    the messages on Anna's phone, Raf's phone, and JC's
  //    phone in that order. Follow the README for an example.
  // ======================================================
  std::cout << "Printing messages sent to ";

  std::cout << "\n";
  std::cout << "Printing messages sent to ";

  std::cout << "\n";
  std::cout << "Printing messages sent to ";
}