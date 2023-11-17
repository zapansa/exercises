#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <memory>
#include <string>

#include "account.h"

class Bank {
 public:
  Bank(const std::string &bank_name_);

  const std::string &GetBankName() const 
  { 
    return bank_name_; 
  }

  const std::map<int, Account> &GetAccounts() const 
  { 
    return accounts_; 
  }
    
  void CreateAccount(const std::string &account_holder_name_, double initial_balance_);

  int TotalAccounts() 
  { 
    return GetAccounts().size();
  }

  void DisplayBalances();

  void DeactivateAccount(int id_);

  private:
    // We provided this helper function to you to randomly generate
    // a new Bank Account ID to be used in CreateAccount.
    int GenerateAccountId() const
    {
      return std::rand() % 9000 + 1000; // [1000, 9999]
    }

    std::string bank_name_;
    std::map<int, Account> accounts_;
  };