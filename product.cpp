// code for product struct here
#include "product.h"
using namespace std;

string product::product_info() {
  string price_str = to_string(price);
  price_str = price_str.substr(0, price_str.find('.') + 3);
  return "Name: " + name + "\nDescription: " + description + "\nPrice: $" + price_str + "\n";

}
