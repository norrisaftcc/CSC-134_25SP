// CSC 134
// M2LAB1 - boxes
// norrisa
// 2/10/2025

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "Crate Calculation Program" << endl;
    // variables
    int length, width, height;
    int volume;
    // constants - never change
    const double COST_PER = 0.23;   // $ per cubic foot
    const double CHARGE_PER = 0.50;
    // money variables
    double cost, charge, profit;    // cost is to make, charge is what consumer pays

    // Ask user what crate they want
    cout << "Enter the dimensions of the crate (in cubic feet)." << endl;
    cout << "Length: ";
    cin >> length;
    cout << "Width: ";
    cin >> width;
    cout << "Height: ";
    cin >> height;

    // Do the math
    volume = length * width * height;
    cost = COST_PER * volume;
    charge = CHARGE_PER * volume;
    profit = charge - cost; // example: $0.50 box, costs $0.23, so $0.27 profit

    // print the results
    // format the results
    cout << setprecision(2) << fixed << showpoint;
    cout << "A crate " << length << " by " << width << " by " << height << endl;
    cout << "Is volume: " << volume << endl;
    cout << "It costs:  $" << cost << " to make." << endl;
    cout << "Sells for: $" << charge << endl;
    cout << "Profit is: $" << profit << endl;

    // done!
    return 0; // no errors
}