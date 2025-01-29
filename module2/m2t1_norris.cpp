// CSC 134 
// M2T1 - The Apple Orchard Part 2
// norris
// 1/29/2025
// We're going to make the simplest possible
// "checkout" machine.
// Today's features to add:
// Ask for user input: name, and how many apples they want
// Only charge them for that many apples

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Apple sales program
    // Variables are like mailboxes
    string farm_name = "Norris"; // you do whatever name you want
    int num_apples = 10;    // int are whole numbers: 1, 2, 100000, 42
    double cost_each = 0.25;// twenty five cents, or $0.25.
    // new variables for M2T1
    string user_name;       // Who is buying apples? 
    int apples_to_buy;      // How many do they want.

    // Greet the customer
    cout << "Hello! What's your name? ";
    cin >> user_name;
    cout << "Thanks for coming by, " << user_name << "!" << endl;

    cout << "Welcome to the " << farm_name << " apple farm!" << endl;
    cout << "There are " << num_apples << " apples in stock." << endl;
    cout << "They cost $" << cost_each << " each." << endl;

    // This line sets cout for doubles to 2 decimal places
    // you must put the line #include <iomanip> with the other #include statements up top
    cout << setprecision(2) << fixed;

    // Find out the total price
    double total_cost = num_apples * cost_each;
    cout << "The price for all of them is: $" << total_cost << endl;

    // Now let's make a deal

    cout << endl;
    return 0; // no errors
}