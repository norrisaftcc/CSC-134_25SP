// CSC 134
// M2T2 - Receipt
// teacherbot
// 2/3/2025


#include <iostream>
#include <iomanip>         // for the 2 decimal place trick
using namespace std;
  
int main()
{
   // setup
   string store_name = "Norris' Tacos";
   string food_name = "taco";
   double food_price = 5.99; // $
   int    how_many; 

   // Our receipt variables
   double subtotal, total;
   double tax_percent, tax_cost;

   // Do the order
   cout << "Welcome to the " << store_name << " store!" << endl;
   cout << "We sell " << food_name << " and it's $" << food_price << " each." << endl;
   cout << "How many do you want? ";
   cin  >> how_many;

   // Calculate subtotal, tax, total
   tax_percent = 0.08; // assignment says 8%, so 8/100 (as a double)
   subtotal = food_price * how_many;
   tax_cost = subtotal * tax_percent; // 8% of $5.99
   total    = subtotal + tax_cost;
   // Print the receipt
   // Tried two ways to line up : setw() and tab \t 
   cout << setprecision(2) << fixed; // magic to turn on 2 decimals
   cout << food_name << " x " << how_many << endl;
   cout << "------------------------------------" << endl;
   cout << setw(12) << "Subtotal:\t$"  << setw(6) << subtotal << endl;
   cout << setw(12) << "Tax (8%):\t$"  << setw(6) << tax_cost << endl;
   cout << "------------------------------------" << endl;
   cout << setw(12) << "Total:\t$"     << setw(6) << total    << endl;
   cout << "------------------------------------" << endl;

   cout << "Have a nice day!" << endl;
   return 0;
}
