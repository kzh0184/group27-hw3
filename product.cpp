// code for product struct here
#include "product.h"

std::string product::product_info() {
  return "Name: " + name + "\nDescription: " + description + "\nPrice: $" +
         std::to_string(price) + "\n";
}
