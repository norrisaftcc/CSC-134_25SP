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
    
    string store_name = "Norris' Burgers and Fries"; 
    string food_name = "burger";
    double food_price = 5.99;   // we can make this input later
    // Do the order
    cout << "Welcome to " << store_name << endl;
    cout << "You have one " << food_name;
    cout << " which costs $" << food_price << endl;


    // Figure out the subtotal and total
    double subtotal, total;
    subtotal = food_price; // changes if they buy more
    
    // Remember tax is two things, the percent and the $
    double tax_percent = 0.08; // 8% is 8/100
    double tax_cost = tax_percent * subtotal;
    total = subtotal + tax_cost;

    // Print the receipt
    cout << setprecision(2) << fixed; // magic words for 2 decimals
    // \t is the tab key
    cout << "YOUR RECEIPT" << endl;
    cout << "-----------------------" << endl;
    cout << "Subtotal:\t$" << subtotal << endl;
    cout << "Tax:\t\t$" << tax_cost << endl;
    cout << "-----------------------" << endl;
    cout << "Total:\t\t$" << total << endl;
    cout << "Have a nice day!" << endl;
    cout << endl; 
    return 0; // no errors
}