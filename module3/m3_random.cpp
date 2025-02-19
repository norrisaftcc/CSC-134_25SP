// CSC 134
// M3 Random Numbers Example
// norrisa
// 2/19/2025
// Start with dice rolls


#include <iostream>
// for pseudo-random numbers
#include <cmath>    
// for making it truly random
#include <ctime>
using namespace std;

int main() {
    cout << "Let's roll some dice!" << endl;
    int seed = time(0);
    //cout << "Your seed is: " << seed << endl;
    //cout << "What's your lucky number? ";
    //cin >> seed;
    // Seed the RNG
    srand(seed);

    const int MAX = 6; // numbers from 1-6
    int roll1, roll2, total;
    roll1  = (rand() % MAX) + 1; // Divide by MAX, and just keep the remainder
    cout << "Your roll was: " << roll1 << endl;

    roll2  = (rand() % MAX) + 1; // Divide by MAX, and just keep the remainder
    cout << "Your roll was: " << roll2 << endl;

    total = roll1 + roll2;
    cout << "Your total roll is: " << total << endl;

    // Let's play craps!
    // 7 and 11 - win!
    // 2 and 12 - lose.
    // anything else -- comes later.
    if (total == 7) {
        cout << "Lucky seven! You win!" << endl;
    }
    else if (total == 11) {
        cout << "Eleven is a winner!" << endl;
    }
    else if (total == 2) {
        cout << "Snake eyes! Too bad, you lose." << endl;
    }
    else if (total == 3) {
        cout << "Sorry, three is unlucky, you lose." << endl;
    }
    else if (total == 12) {
        cout << "Boxcars! Sorry, you lost." << endl;
    }
    else {
        // anything else
        cout << "Your point is " << total << " but we'll do that part later" << endl;
    }

    return 0;
}