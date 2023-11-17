#include "bank.h"

Bank::Bank(const std::string &bank_name_){}

void Bank::CreateAccount(const std::string &account_holder_name_, double initial_balance_)
{
    Account new_account = Account(account_holder_name_, initial_balance_);
    int rand_id = GenerateAccountId();
    accounts_.insert({rand_id, new_account});
}

void Bank::DisplayBalances()
{
    std::map<int, Account>::iterator i = accounts_.begin(); 
    while (i != accounts_.end())
    {
        Account acc = i->second; 
        std::string acc_name = acc.GetAccountHolder(); 
        double acc_balance = acc.GetBalance(); 
        std::cout << acc_name << ": $" << acc_balance << "\n";
        i++;
    }
}

void Bank::DeactivateAccount(int id_) 
{
    std::map<int, Account>::iterator iter = accounts_.find(id_);
    if (iter != accounts_.end()){
        // implement erase account
    }
    else
    {
        std::cout << "\nAccount does not exist.\n";
    }
}
