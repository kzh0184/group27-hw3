// code for person class here
#include "person.h"
#include "address.h"
#include "credit_card.h"
#include <string>
Person::Person(std::string name, std::string phone, address addr,
               credit_card card) {
  name_ = name;
  phone_ = phone;
  person_address_ = addr;
  person_credit_card_ = card;
}

Person::Person() {
  name_ = "";
  phone_ = "";
  person_address_ = address();
  person_credit_card_ = credit_card();
}

void Person::name(std::string name) { name_ = name; }

std::string Person::name() { return name_; }

void Person::phone(std::string phone) { phone_ = phone; }

std::string Person::phone() { return phone_; }

void Person::person_address(address addr) { person_address_ = addr; }

address Person::person_address() { return person_address_; }

void Person::person_credit_card(credit_card card) {
  person_credit_card_.cc_number = card.cc_number;
  person_credit_card_.limit = card.limit;
  person_credit_card_.current_balance = card.current_balance;
}

credit_card Person::person_credit_card() { return person_credit_card_; }

std::string Person::person_info() {
  std::string message = "";
  message += "Name: " + name() + "\n";
  message += "Phone: " + phone() + "\n";
  message += "Address: " + person_address().address_info() + "\n";
  message += "Credit Card: " + person_credit_card().credit_card_info() + "\n";
  return message;
}
