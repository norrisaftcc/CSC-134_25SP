// CSC 134 
// M1Lab1 - The Apple Orchard
// norris
// 1/27/2025
// We're going to make the simplest possible
// "checkout" machine.

#include <iostream>
using namespace std;

int main() {
    // Apple sales program
    // Variables are like mailboxes
    string name = "Norris"; // you do whatever name you want
    int num_apples = 10;    // int are whole numbers: 1, 2, 100000, 42
    double cost_each = 0.25;// twenty five cents, or $0.25.

    cout << "Welcome to the " << name << " apple farm!" << endl;
    cout << "There are " << num_apples << " apples in stock." << endl;
    cout << "They cost $" << cost_each << " each." << endl;

    // Find out the total price
    double total_cost = num_apples * cost_each;
    cout << "The price for all of them is: $" << total_cost << endl;

    cout << endl;
    return 0; // no errors
}