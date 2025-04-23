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
    // The magazine contains a mix of red and black shells.
    const int BLACK = 0;
    const int RED = 1;
    const int EMPTY = -1; // do we need this? 

    string shell_names[] = {"Black", "Red", "Empty"};

    // example one: Using a basic array
    int magazine[] = {BLACK, BLACK, RED, RED};
    // in english: "for shell in magazine"
    for (int shell : magazine) {
        string name = shell_names[shell];
        cout << "Next Shell: " << name << endl;
    }

    // Example two: using STL vector
    cout << endl << "VERSION 2" << endl;
    vector<int> mag;
    // load the mag
    mag.push_back(RED);
    mag.push_back(BLACK);
    mag.push_back(BLACK);

    for (int shell: mag) {
        string name = shell_names[shell];
        cout << "Next Shell: " << name << endl;
    }

}