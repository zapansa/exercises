// Christian Siquian
// CPSC 121L-01
// 11/14/23
// chrissiquian@csu.fullerton.edu
// chrissiquian
//
// Lab 11-1

#include "customer.h"

// ========================= YOUR CODE HERE =========================
// This implementation file (customer.cc) is where you should implement
// the member functions declared in the header (customer.h), only
// if you didn't implement them inline within customer.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the Customer class.
// ===================================================================
int Customer::TotalCustomersInLine() const {
  if (next_customer_ == nullptr) {
    return 1;
  } else {
    return next_customer_->TotalCustomersInLine() + 1;
  }
}
int Customer::TotalProductsInLine() const {
  if (next_customer_ == nullptr) {
    return product_count_;
  } else {
    return next_customer_->TotalProductsInLine() + product_count_;
  }
}
std::string Customer::FirstAlphabeticalCustomerInLine() const {
  if (next_customer_ == nullptr) {
    return name_;
  } else {
    const std::string& recursive_name =
        next_customer_->FirstAlphabeticalCustomerInLine();
    if (name_ < recursive_name) {
      return name_;
    } else {
      return recursive_name;
    }
  }
}
