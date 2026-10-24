#include "transaction.h"
#include <string>

int transaction_number;
Person customer;
product purchased_item;
int quantity;
using namespace std;

// prints information about one transaction
std::string transaction::transaction_info() {
  return  "Transaction #: " + to_string(transaction_number) + "\n" +
          "Customer:\n" + customer.person_info() +
          "Product:\n" + purchased_item.product_info() +
          "Quantity: " + to_string(quantity) + "\n";

          
}
