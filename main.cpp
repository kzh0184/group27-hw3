#include <iostream>
#include <fstream>
#include <string>
#include <random>

#include "address.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"
#include "store.h"
#include "transaction.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::string;

int main()
{
  // configure std output 
	//import from text files
	ifstream people_file("people.txt");
	if (!people_file.is_open())
	{
		cout << "Error opening people.txt" << endl;
		return 1;
	}
	int num_people = 0;
	people_file >> num_people;
	people_file.ignore(); // ignore the newline character after the number of people
	
	ifstream cc_file("credit_card.txt");
	if (!cc_file.is_open())
	{
		cout << "Error opening credit_cards.txt" << endl;
		return 1;
	}
	int num_cc = 0;
	cc_file >> num_cc;
	cc_file.ignore(); // ignore the newline character after the number of credit cards


	//add to store and other variables
	Store store1;
	store1.num_customers(num_people);
	for (int i = 0; i < num_people; i++)
	{
		///read from people.txt
		string name, phone, line1, line2, city, state, zip;
		getline(people_file, name);
		getline(people_file, phone);
		getline(people_file, line1);
		getline(people_file, line2);
		getline(people_file, city);
		getline(people_file, state);
		getline(people_file, zip);

		///read from credit_cards.txt
		int cc;
		double cc_limit, cc_balance;
		cc_file >> cc;
		cc_file >> cc_limit;
		cc_file >> cc_balance;
		cc_file.ignore(); // ignore the newline character

		///temp address, credit card, and person objects
		address temp_address{line1, line2, city, state, zip};
		credit_card temp_cc{cc, cc_limit, cc_balance};
		Person temp_person{name, phone, temp_address, temp_cc};
		store1.add_customer(temp_person);

	}
	people_file.close();
	cc_file.close();

	///product
	ifstream product_file("products.txt");
	if (!product_file.is_open())
	{
		cout << "Error opening products.txt" << endl;
		return 1;
	}
	int num_products = 0;
	product_file >> num_products;
	product_file.ignore(); // ignore the newline character after the number of products
	// store1.num_products(num_products);
	for (int i = 0; i < num_products; i++)
	{
		string product_name, product_description;
		getline(product_file, product_name);
		getline(product_file, product_description);
		double product_price;
		product_file >> product_price;
		product_file.ignore(); // ignore the newline character after the price

		product temp_product{product_name, product_description, product_price};
		store1.add_product(temp_product);
	}
  std::cout << store1.num_products() << '\n';
	product_file.close();
	
	//print store info after you finish importing info
	//from text files and add them to your store
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;

	//make random number of random transactions
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> transaction_distrib(1,100); // random amount of transactions;
  std::uniform_int_distribution<> product_distrib(1,10); // random product;
  std::uniform_int_distribution<> person_distrib(1,store1.num_customers()); // random product;
  int num_transactions = transaction_distrib(gen);
  transaction purchase;

  for(int i = 0; i < num_transactions; i++){
    purchase.purchased_item = store1.get_product(product_distrib(gen));
    purchase.quantity= product_distrib(gen);
    purchase.transaction_number = store1.num_transactions() + 1;
    purchase.purchased_item = store1.get_product(product_distrib(gen));
    purchase.customer = store1.get_customer(person_distrib(gen));
    store1.add_transaction(purchase);
  }

	//print store info at the end
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;
}
