// CSC 134
// M1LAB1 - Apple Sales
// norrisa
// 1/27/2025
// Today we're selling apples

#include <iostream>
#include <iomanip>
using namespace std;
  
int main()
{
    // Declare your variables (boxes to hold data)
    string name = "Norris";         // strings hold words, sentences, names, ...
    int num_apples = 100;           // int are whole numbers (no decimal)
    double price_each = 0.25;       // any number with a decimal is a double

    // Say hi
    cout << "Welcome to the " << name << " apple farm." << endl;
    cout << "We have " << num_apples << " apples in stock." << endl;
    cout << "Price per apple is: $" << price_each << endl;
    cout << endl;

    // Calculate total
    double total_cost = num_apples * price_each;

    // print answer
    cout << fixed << setprecision(2); // this makes it print 25.00 instead of 25
    cout << "The total for all " << num_apples << " is $" << total_cost << endl;

    return 0; // no errors

}
