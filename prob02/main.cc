#include <iostream>
#include <memory>
#include <vector>

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
  Phone anna = Phone("Anna");
  Phone raf = Phone("Raf");
  Phone jc = Phone("JC");
  std::shared_ptr<Phone> phone1 = std::make_shared<Phone>(anna);
  std::shared_ptr<Phone> phone2 = std::make_shared<Phone>(raf);
  std::shared_ptr<Phone> phone3 = std::make_shared<Phone>(jc);

  // =================== YOUR CODE HERE ===================
  // 2. Add each phone to the Network, `csuf_network`.
  // ======================================================
  csuf_network.AddPhone(phone1);
  csuf_network.AddPhone(phone2);
  csuf_network.AddPhone(phone3);

  // =================== YOUR CODE HERE ===================
  // 3. Send the message "Sup" to Raf over the network,
  //    authored on Anna's phone.
  // ======================================================
  std::shared_ptr<Message> m1 = phone1->AuthorMessage("Sup");
  csuf_network.SendMessage(m1, "Raf");

  // =================== YOUR CODE HERE ===================
  // 4. Send the message "Lol" to Anna over the network,
  //    authored on Raf's phone.
  // ======================================================
  std::shared_ptr<Message> m2 = phone2->AuthorMessage("Lol");
  csuf_network.SendMessage(m2, "Anna");

  // =================== YOUR CODE HERE ===================
  // 5. Create a vector of strings containing "Anna" and
  //    "Raf" called `jcs_class`. Call the SendMessage
  //     overload to author a message on JC's phone and send
  //     the message "Hi class!" to everyone in `jcs_class`.
  // ======================================================
  std::vector<std::string> jcs_class = {"Anna", "Raf"};
  std::shared_ptr<Message> m3 = phone3->AuthorMessage("Hi class!");
  csuf_network.SendMessage(m3, jcs_class);

  // =================== YOUR CODE HERE ===================
  // 6. Send the message "Hi Prof!" to JC over the network,
  //    authored on Anna's phone.
  // ======================================================
  std::shared_ptr<Message> m4 = phone1->AuthorMessage("Hi Prof!");
  csuf_network.SendMessage(m4, "JC");

  // =================== YOUR CODE HERE ===================
  // 7. Send the message "help how do C++" to JC over the
  //    network, authored on Raf's phone.
  // ======================================================
  std::shared_ptr<Message> m5 = phone2->AuthorMessage("help how do C++");
  csuf_network.SendMessage(m5, "JC");

  // =================== YOUR CODE HERE ===================
  // 8. Complete the std::cout statements below to display
  //    the messages on Anna's phone, Raf's phone, and JC's
  //    phone in that order. Follow the README for an example.
  // ======================================================
  std::cout << "Printing messages sent to Anna";
  phone1->PrintMessages();
  std::cout << "\n\n";

  std::cout << "Printing messages sent to Raf";
  phone2->PrintMessages();
  std::cout << "\n\n";

  std::cout << "Printing messages sent to JC";
  phone3->PrintMessages();
  std::cout << "\n\n";
}