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
    string stat_names[] = {"STR","DEX","CON","INT","WIS","CHA"};
    int current_stat;   // for user input
    double total_stats = 0; // double makes average be double
    double average_stat;// total / num_stats
    
    cout << "Please enter your character stats." << endl;
    for (int i=0; i<NUM_STATS; i++) {
        cout << "Stat (" << stat_names[i] << "): ";
        cin >> current_stat;
        stats[i] = current_stat;
        total_stats += current_stat;
    }
    // Find total and average
    average_stat = total_stats / NUM_STATS;
    // print all the stats
    cout <<"Total: " << total_stats << " Average: " << average_stat << endl;
    cout << "Character Sheet:" << endl;
    for (int i=0; i<NUM_STATS; i++) {
        cout << stat_names[i] << ": " << stats[i] << endl;
    }
}
