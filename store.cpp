//code for store class here
#include"store.h"
Store::Store() {
  num_customers_ = 0;
  num_products_ = 0;
  num_transactions_ = 0;
}
void Store::num_products(int product_count) {
  num_products_ = product_count;
}
int Store::num_products(){
  return num_products_;
}
void Store::num_customers(int customer_count) {
  num_customers_ = customer_count;
}

int Store::num_customers(){
  return num_customers_;
}

void Store::num_transactions(int transaction_count) {
  num_transactions_ = transaction_count;
}

int Store::num_transactions(){
  return num_transactions_;
}

bool Store::add_product(product item) {
  if(num_products_ > std::size(products_) -1) {
    return false; // not enough space in array
  } 
  num_products_ += 1;
  products_[num_products_] = item;
  return true; 
}

bool Store::add_customer(Person customer) {
  if(num_customers_ > std::size(customers_)-1) {
    return false; // not enough space in array
  }
  num_customers_ += 1;
  customers_[num_customers_] = customer;
  return true; 
}

bool Store::update_customer(int index, Person customer) {
  if(index < 0 || index > std::size(customers_)){ // index out of bounds
    return false;
  }
  customers_[index] = customer;
  return true;
}
product Store::get_product(int index) {
  return products_[index];
}
