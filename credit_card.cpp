//implementation code for credit_card struct here
#include "credit_card.h"
#include <iostream>
using namespace std;

	//method to make a purchase against the 
	//credit card limit. returns true if 
	//successfull and false otherwise. 
bool credit_card::make_purchase(double purchase_amount)
{
    if (current_balance + purchase_amount < limit){
        current_balance += purchase_amount;
        return true;
    }
    else{return false;}

}

	//method to make a payment towards the credit
	//card balance. returns true if
	//successfull and false otherwise.
bool credit_card::make_payment(double payment_amount) {

    if (payment_amount <= 0.0) {//fail if payment amount is negative or zero (invalid payment)
        return false;
    }
    if (payment_amount > current_balance) {//fail if exceed balance
        return false; 
    }
    current_balance -= payment_amount;
    return true;
}


	//method to print credit card details
std::string credit_card::credit_card_info()
{
    // Convert the numeric limits to strings
    string limit_str = std::to_string(limit);
    string balance_str = std::to_string(current_balance);

    // Trim the extra zeros off the doubles to keep exactly 2 decimal places
    limit_str = limit_str.substr(0, limit_str.find('.') + 3);
    balance_str = balance_str.substr(0, balance_str.find('.') + 3);

    // return 1 string
    string output = "Credit Card:\nCredit card number: " + std::to_string(cc_number) + "\n" +
           "Credit Card Limit: $" + limit_str + "\n" +
           "Current Balance: $" + balance_str + "\n";
               return output;
        }
    
/*int main()
{
    credit_card john;
    john.cc_number = 123456789;
    john.limit = 1000.00;
    john.current_balance = 0.00;
    john.make_purchase(500.00);
    john.make_payment(200.00);
    std::cout << john.credit_card_info();
    return 0;
}*/