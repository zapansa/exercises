#include <iostream>
#include <memory>
#include <vector>

#include "network.h"
#include "phone.h"
 


void AssignmentStart(){
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

void Border(int x)
{
  for (auto i = 1; i <= x; i++)
  {
    std::cout << "-";
  };
}
void Title(std::string x){
  std::cout << "\n +              " << x << "\n";
}

Network DemoStartInitializeNetwork(){
  // Demo Netword
  Network demo_network;

  // Demo people
  Phone anna = Phone("Anna");
  Phone raf = Phone("Raf");
  Phone jc = Phone("JC");
  Phone chris = Phone("Chris");
  Phone juju = Phone("Juju");
  Phone pookie = Phone("Pookie");
  Phone thot = Phone("Thot");

  // Pointers
  std::shared_ptr<Phone> phone1 = std::make_shared<Phone>(anna);
  std::shared_ptr<Phone> phone2 = std::make_shared<Phone>(raf);
  std::shared_ptr<Phone> phone3 = std::make_shared<Phone>(jc);
  std::shared_ptr<Phone> phone4 = std::make_shared<Phone>(chris);
  std::shared_ptr<Phone> phone5 = std::make_shared<Phone>(juju);
  std::shared_ptr<Phone> phone6 = std::make_shared<Phone>(pookie);
  std::shared_ptr<Phone> phone7 = std::make_shared<Phone>(thot);

  // Add to network
  demo_network.AddPhone(phone1);
  demo_network.AddPhone(phone2);
  demo_network.AddPhone(phone3);
  demo_network.AddPhone(phone4);
  demo_network.AddPhone(phone5);
  demo_network.AddPhone(phone6);
  demo_network.AddPhone(phone7);

  // Demo Messages
  // ======================================================
  std::shared_ptr<Message> m1 = phone1->AuthorMessage("Sup");
  demo_network.SendMessage(m1, "Raf");
  std::shared_ptr<Message> m2 = phone1->AuthorMessage("I hate this shit.");
  demo_network.SendMessage(m2, "Raf");
  std::shared_ptr<Message> m3 = phone1->AuthorMessage("Fuck U.");
  demo_network.SendMessage(m3, "Chris");

  std::shared_ptr<Message> m4 = phone2->AuthorMessage("Heyy!");
  demo_network.SendMessage(m4, "Anna");
  std::shared_ptr<Message> m5 = phone2->AuthorMessage("u suck");
  demo_network.SendMessage(m5, "JC");
  std::shared_ptr<Message> m6 = phone2->AuthorMessage("Banana eater");
  demo_network.SendMessage(m6, "Chris");

  std::vector<std::string> jcs_class = {"Anna", "Raf", "Thot", "Chris", "Juju"};
  std::shared_ptr<Message> m7 = phone3->AuthorMessage("Hi class!");
  demo_network.SendMessage(m7, jcs_class);

  std::vector<std::string> hoeing = {"Anna", "Raf", "Thot", "JC", "Pookie"};
  std::shared_ptr<Message> m8 = phone4->AuthorMessage("WYD ;)");
  std::shared_ptr<Message> m82 = phone4->AuthorMessage("Stop airing me!!");  
  std::shared_ptr<Message> m83 = phone4->AuthorMessage("wyddddddd");
  std::shared_ptr<Message> m9 = phone4->AuthorMessage("i hate u ur awful i hate u!!");
  demo_network.SendMessage(m8, hoeing);
  demo_network.SendMessage(m82, hoeing);
  demo_network.SendMessage(m83, hoeing);
  demo_network.SendMessage(m9, "Juju");

  std::shared_ptr<Message> m10 = phone5->AuthorMessage("why man");
  demo_network.SendMessage(m10, "Chris");
  return demo_network;
}

void DemoViewNetwork(int border, std::string title, Network demo_network){
  using namespace std;
  int user_opt;
  int i = 1;

  cout << "\n";
  Border(border);
  Title(title);
  Border(border);
  cout << "\n";

  for (const auto &[key, value] : demo_network.getPhonebook())
  {
    cout << i << ". ";
    cout << key << "\n";
    i++;
  }
}

void DemoViewMessages(int border, std::string title, Network demo_network){
  using namespace std;

  cout << "\n";
  Border(border);
  Title(title);
  Border(border);
  cout << "\n";
  cout << "\n";
  cout << "Whose messages would you like to view?\n";
  cout << "Note ** Names are case sensitive.\n\n";
  cout << "Name: ";

  string name; 
  cin >> name;

  if (demo_network.getPhonebook().count(name) > 0){
    cout << "\033[2J\033[;H";
    cout << "\n";
    Border(border);
    Title(name +"'s Messages");
    Border(border);
    cout << "\n";
    demo_network.getPhonebook().at(name)->PrintMessages();
    cout << "\n";
  }
  else{
    cout << "This person does not exist.\n";
  }
}

void DemoStartMenu(int border, std::string title, Network demo_network)
{
  using namespace std;  


  while (true){  
    int user_opt;
    cout << "\n";
    Border(border);
    Title(title);
    Border(border);
    cout << "\n";

    string options[2] = {"1. View Network", "2. View Messages"};
    cout << "\n";
    for (string x : options)
    {
      cout << x << "\n";
    }
    cout << "\n";
    cout << "\n";

    cout << "Option: ";
    cin >> user_opt;

    switch (user_opt)
    {
    case 1:
      cout << "\033[2J\033[;H";
      DemoViewNetwork(border, "Network", demo_network);
      break;
    case 2:
      cout << "\033[2J\033[;H";
      DemoViewMessages(border, "View Messages", demo_network);
      break;
    default:
      exit(0);
    }
  }

  
}

void DemoStart(int border, std::string title){
  Network network = DemoStartInitializeNetwork();
  DemoStartMenu(border, title, network);

}

int main()
{
  system("cls");

  using namespace std;
  int border_len = 40;

  cout << "\n";
  Border(border_len);
  Title("Main Menu");
  Border(border_len);
  cout << "\n";

  string options[2] = {"1. Run Assignment", "2. Run Preset Demo",};
  cout << "\n";
  for(string x : options){ cout << x << "\n";}
  cout << "\n";
  cout << "\n";

  int user_opt;
  cout << "Option: ";
  cin >> user_opt; 

  switch(user_opt){
    case 1:
      cout << "\033[2J\033[;H";
      AssignmentStart();
      break;
    case 2:
      cout << "\033[2J\033[;H";
      DemoStart(border_len, "Demo Menu");
      break;
  }
}

