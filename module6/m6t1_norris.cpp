/*
CSC 134
M6T1 - Basic Arrays
norrisa
4/7/25

For each day Monday through Friday:
  count the cars that pass the site
  add them to the total
Find the total
Find the average per day
*/

#include <iostream>
using namespace std;

int main() {
    // First version - no array
    const int DAYS = 5;
    int cars_today;
    int cars_total = 0;
    double cars_average;
    // Add array holding car counts
    int cars[DAYS];

    cout << "Enter cars that pass for each day." << endl;
    for (int i=0; i<DAYS; i++) {
        cout << "Day " << i+1 << ": " ;
        cin >> cars_today;
        cars[i] = cars_today; // save today's value in the array
        cars_total += cars_today;
    }
    cout << "Over " << DAYS << " days, total cars = " << cars_total << endl;
    cars_average = (double) cars_total / DAYS; // don't want to round off too eary
    cout << "For an average of " << cars_average << " each day." << endl;

    // Now, print the array
    for (int i=0; i<DAYS; i++) {
        cout << "Day: " << i+1 << " Count: " << cars[i] << endl;
    }
}