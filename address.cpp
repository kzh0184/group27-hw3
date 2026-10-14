//implementation code for address struct here
#include <iostream>
#include "address.h"
using namespace std;

string address::address_info() {
    return address_line1 + "\n" + 
           address_line2 + "\n" + 
           city + "\n" + 
           state + "\n" + 
           zip + "\n";
}
