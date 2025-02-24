// CSC 134
// M3 Random Numbers Example
// norrisa
// 2/24/2025
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

    // Add our constants
    // lose on 2, 3, 12
    const int SNAKE_EYES = 2;
    const int UNLUCKY_THREE = 3;
    const int BOX_CARS   = 12;
    // win on 7, 11
    const int LUCKY_SEVEN  = 7;
    const int LUCKY_ELEVEN = 11;

    if (LUCKY_SEVEN == total) {
        cout << "Lucky seven! You win!" << endl;
    }
    else if (LUCKY_ELEVEN == total) {
        cout << "Eleven is a winner!" << endl;
    }
    else if (SNAKE_EYES == total) {
        cout << "Snake eyes! Too bad, you lose." << endl;
    }
    else if (UNLUCKY_THREE == total) {
        cout << "Sorry, three is unlucky, you lose." << endl;
    }
    else if (BOX_CARS == total) {
        cout << "Boxcars! Sorry, you lost." << endl;
    }
    else {
        // anything else
        cout << "Your point is " << total << " but we'll do that part later" << endl;
    }
    return 0;
}