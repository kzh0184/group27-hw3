//implementation code for credit_card struct here
#include "credit_card.h"

//method to make a purchase against the 
//credit card limit. returns true if 
//successfull and false otherwise. 
bool credit_card::make_purchase(double purchase_amount){
  if(current_balance + purchase_amount > limit) {
    return false;
  }
  current_balance+= purchase_amount;
  return true;
};

//method to make a payment towards the credit
//card balance. returns true if
//successfull and false otherwise.
bool credit_card::make_payment(double payment_amount){
  if(current_balance-payment_amount < 0){
    return false;
  }
  current_balance -= payment_amount;
  return true;
};

//method to print credit card details
std::string credit_card::credit_card_info() {
  std::string message = "Number: "; 
  message += std::to_string( cc_number);
  message += "\nLimit: ";
  std::string limit_str =  std::to_string(limit);
  limit_str = limit_str.substr(0,limit_str.find('.') + 3);
  message += limit_str;
  message += "\nCurrent Balance: ";
  std::string balance_str = std::to_string(current_balance);
  balance_str = balance_str.substr(0,balance_str.find('.') + 3);
  message += balance_str;
  message += "\n";   
  return message;
};
