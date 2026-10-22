// code for store class here
#include "store.h"

Store::Store() {
  num_customers_ = 0;
  num_products_ = 0;
  num_transactions_ = 0;
}

void Store::num_products(int product_count) { num_products_ = product_count; }

int Store::num_products() { return num_products_; }

void Store::num_customers(int customer_count) {
  num_customers_ = customer_count;
}

int Store::num_customers() { return num_customers_; }

void Store::num_transactions(int transaction_count) {
  num_transactions_ = transaction_count;
}

int Store::num_transactions() { return num_transactions_; }

bool Store::add_product(product item) {
  if (num_products_ > std::size(products_) - 1) {
    return false; // not enough space in array
  }
  products_[num_products_] = item;
  num_products_ += 1;
  return true;
}

bool Store::add_customer(Person customer) {
  if (num_customers_ > std::size(customers_) - 1) {
    return false; // not enough space in array
  }
  customers_[num_customers_] = customer;
  num_customers_ += 1;
  return true;
}

bool Store::add_transaction(transaction trans) {
  if (num_transactions_ > std::size(transactions_) - 1) {
    return false; // not enough space in array
  }
  num_transactions_ += 1;
  transactions_[num_transactions_] = trans;
  return true;
}

bool Store::update_customer(int index, Person customer) {
  if (index < 0 || index > std::size(customers_)) { // index out of bounds
    return false;
  }
  customers_[index].name(customer.name());
  customers_[index].phone(customer.phone());
  customers_[index].person_address(customer.person_address());
  customers_[index].person_credit_card(customer.person_credit_card());
  return true;
}

Person Store::get_customer(int index) { return customers_[index]; }

product Store::get_product(int index) { return products_[index]; }

std::string Store::store_info() {
  std::string out_string = "";
  out_string +=
      "Customers: \n Count: " + std::to_string(num_customers()) + '\n';
  for (int i = 0; i < num_customers(); i++) {
    Person *customer = &Store::customers_[i];
    if (customer != nullptr) {
      out_string += customer->person_info();
    }
  }
  out_string += "Products: \n Count: " + std::to_string(num_products()) + '\n';
  for (int i = 0; i < num_products(); i++) {
    product *product = &Store::products_[i];
    if (product != nullptr) {
      out_string += product->product_info();
    }
  }
  out_string +=
      "\nTransactions: \nCount: " + std::to_string(num_transactions()) + '\n';
  for (int i = 0; i < num_transactions(); i++) {
    transaction *transaction = &Store::transactions_[i];
    if (transaction != nullptr) {
      out_string += transaction->transaction_info();
    }
  }
  return out_string;
}
