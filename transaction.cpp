#include <string>
#include "transaction.h"


	int transaction_number;
	Person customer;
	product purchased_item;
	int quantity;

	//prints information about one transaction
	std::string transaction::transaction_info()
    {
        return "Transaction Number: " + std::to_string(transaction_number) + "\n" +
               customer.person_info() +
               purchased_item.product_info() +
               "Quantity: " + std::to_string(quantity) + "\n";
    }

