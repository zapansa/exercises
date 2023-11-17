// Please fill in below.
// <Your name>
// <Your section number> (e.g. CPSC 121L-01)
// <Date>
// <Your csu.fullerton.edu email>
// <Your GitHub username>
//
// Lab 10-2
// If it is a pair programming lab please specify partner below.
// Partner: @peteranteater

#include <iostream>
#include <map>
#include <vector>

#include "bank.h"

int main() {
  Bank banksy = Bank("Banksy");

  banksy.CreateAccount("Tuffy", 121.00);
  banksy.CreateAccount("Frank", 1234.56);
  banksy.CreateAccount("Oreo", 140.12);


  for (auto [id, account] : banksy.GetAccounts())
  {
    if(account.GetAccountHolder() == "Tuffy")
    {
      banksy.DeactivateAccount(id);
    }
  }

  banksy.DisplayBalances();
}
