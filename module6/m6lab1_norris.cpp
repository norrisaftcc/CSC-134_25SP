/*
CSC 134
M6LAB1 - Buckshot Roulette
norrisa
4/21/25
*/

#include <vector>
#include <iostream>
using namespace std;

int main() {

    // Idea is to replicate the simplest parts of Buckshot Roulette.
    // Variables
    const int RED = 1;
    const int BLACK = 2;
    const int EMPTY = 0; // do we need this? We would with an array

    // example one: Using a basic array
    int magazine[] = {RED, BLACK, BLACK, RED};
    for (int shell : magazine) {
        string shellname;
        if (shell == BLACK) {
            shellname = "Black";
        }
        if (shell == RED) {
            shellname = "Red";
        }
        cout << "Next shell: " << shellname << endl;
    }






    return 0;
}