#include <fstream>
#include <iostream>
#include <random>
#include <string>

#include "address.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"
#include "store.h"
#include "transaction.h"

using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::string;

int main() {
  // configure std output
  // import from text files
  ifstream people_file("people.txt");
  if (!people_file.is_open()) {
    cout << "Error opening people.txt" << endl;
    return 1;
  }
  int num_people = 0;
  people_file >> num_people;
  // ignore the newline character after the number of people
  people_file.ignore();
  ifstream cc_file("credit_card.txt");
  if (!cc_file.is_open()) {
    cout << "Error opening credit_cards.txt" << endl;
    return 1;
  }
  int num_cc = 0;
  cc_file >> num_cc;
  cc_file.ignore();

  Store store1;
  for (int i = 0; i < num_people; i++) {
    // read from people.txt
    string name, phone, line1, line2, city, state, zip;
    getline(people_file, name);
    getline(people_file, phone);
    getline(people_file, line1);
    getline(people_file, line2);
    getline(people_file, city);
    getline(people_file, state);
    getline(people_file, zip);

    address temp_address = {line1, line2, city, state, zip};
    // start everyone on a dummy card
    credit_card dummy{0, 0, 0};
    Person temp_person = {name, phone, temp_address, dummy};
    store1.add_customer(temp_person);
  }

  // read from credit_cards.txt
  for (int i = 0; i < num_people; i++) {
    int cc;
    double cc_limit, cc_balance;
    std::string name;
    getline(cc_file, name);
    cc_file >> cc >> cc_limit >> cc_balance;
    cc_file.ignore();
    credit_card temp_cc{cc, cc_limit, cc_balance};

    // loop through and assign credit card to right person
    for (int i = 0; i < num_people; i++) {
      Person p = store1.get_customer(i);
      if (p.name() == name) {
        p.person_credit_card(temp_cc);
        store1.update_customer(i, p);
        break;
      }
    }
  }
  people_file.close();
  cc_file.close();

  // product
  ifstream product_file("products.txt");
  if (!product_file.is_open()) {
    cout << "Error opening products.txt" << endl;
    return 1;
  }
  int num_products = 0;
  product_file >> num_products;
  product_file.ignore();
  for (int i = 0; i < num_products; i++) {
    string product_name, product_description;
    getline(product_file, product_name);
    getline(product_file, product_description);
    double product_price;
    product_file >> product_price;
    product_file.ignore(); // ignore the newline character after the price

    product temp_product{product_name, product_description, product_price};
    store1.add_product(temp_product);
  }
  product_file.close();

  // print store info after you finish importing info
  // from text files and add them to your store
  cout << "Store info: " << endl << endl;
  cout << store1.store_info() << endl << endl;

  // make random number of random transactions
  std::random_device rd;
  std::mt19937 gen(rd());
  // random amount of transactions;
  std::uniform_int_distribution<> transaction_distrib(1, 100);
  // random product;
  std::uniform_int_distribution<> product_distrib(1, 10);
  // random buyer;
  std::uniform_int_distribution<> person_distrib(1, store1.num_customers());
  int num_transactions = transaction_distrib(gen);
  transaction purchase;

  for (int i = 0; i < num_transactions; i++) {
    // TODO: add logic to fail transaction if person runs out of money
    purchase.purchased_item = store1.get_product(product_distrib(gen));
    purchase.quantity = product_distrib(gen);
    purchase.transaction_number = store1.num_transactions() + 1;
    purchase.purchased_item = store1.get_product(product_distrib(gen));
    purchase.customer = store1.get_customer(person_distrib(gen));
    store1.add_transaction(purchase);
  }

  // print store info at the end
  cout << "Store info: " << endl << endl;
  cout << store1.store_info() << endl << endl;
}
