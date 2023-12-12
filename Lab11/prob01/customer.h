// Christian Siquian
// CPSC 121L-01
// 11/14/23
// chrissiquian@csu.fullerton.edu
// chrissiquian
//
// Lab 11-1

#include <memory>
#include <string>

class Customer {
 public:
  Customer(const std::string& name, int product_count,
           std::shared_ptr<Customer> next_customer)
      : name_(name),
        product_count_(product_count),
        next_customer_(next_customer) {}

  std::string GetName() const {
    return name_;
  }
  int GetProductCount() const {
    return product_count_;
  }

  std::shared_ptr<Customer> GetNextCustomer() const {
    return next_customer_;
  }

  int TotalCustomersInLine() const;

  int TotalProductsInLine() const;

  std::string FirstAlphabeticalCustomerInLine() const;
  // ====================== YOUR CODE HERE ======================
  // 1. Define a constructor using member initializer list syntax
  //    according to the README.
  // 2. Define the accessor functions (i.e. the getter functions)
  //    `GetName`, `GetProductCount`, and `GetNextCustomer`.
  //    You do not need to create mutator functions (setters).
  // 3. Define the recursive functions specified in the README.
  // ============================================================

 private:
  std::string name_;
  int product_count_;
  std::shared_ptr<Customer> next_customer_;
};
