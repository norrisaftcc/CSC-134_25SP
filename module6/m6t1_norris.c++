/*
CSC 134
M6T1 - Arrays
norrisa
4/7/25
work with D&D stats in an array.
*/
#include <iostream>
using namespace std;

int main() {
    // We have six stats, let's use names for them
    const int NUM_STATS = 6;
    const int STR = 0;
    const int DEX = 1;
    const int CON = 2;
    const int INT = 3;
    const int WIS = 4;
    const int CHA = 5;

    // other variables
    int stats[NUM_STATS];
    int current_stat;   // for user input
    double total_stats; // double makes average be double
    double average_stat;// total / num_stats
    
    cout << "Please enter your character stats." << endl;
    for (int i=0; i<NUM_STATS; i++) {
        cout << "Stat: ";
        cin >> current_stat;
        stats[i] = current_stat;
    }

    cout << "STR: " << stats[STR];


}
