// CSC 134
// M2T2 - Receipts
// norrisa
// 2/3/2025
// We'll make a simple sales program
// that prints "well formatted" receipts
/*
This program should take the price of a meal, which is $5.99, 
and print out a simple text receipt. It should include:
The price before tax
The amount of tax owed (8%)
The total including tax
*/

#include <iostream>
#include <iomanip>  // needed for the 2 decimals thing
using namespace std;

int main() {
    // Set up the variables
    
    string store_name = "NorrisCo"; 
    string food_item = "Burger";
    double food_price = 5.99;   // we can make this input later
    // Do the order
    cout << "Welcome to " << store_name << endl;
    cout << "You have one " << food_item << ", that is $5.99" << endl;

    // Figure out the subtotal and total


    // print the reciept
    cout << "Have a nice day!" << endl;
    cout << endl;
    return 0; // no errors
}