// CSC 134
// M3T1 and M3T2
// norrisa
// 2/17/2025
// Ask the user for the width and length of two rectangles
// Find the area

#include <iostream>
using namespace std;

int main() {
    // Variables
    double len1, wid1, len2, wid2; 
    double area1, area2;

    // Ask user for the length and width
    cout << "What's the length of the first rectangle? ";
    cin >> len1;
    cout << "What's the width of the first rectangle? ";
    cin >> wid1;
    cout << "What's the length of the second rectangle? ";
    cin >> len2;
    cout << "What's the width of the second rectangle? ";
    cin >> wid2;

    // Find the area
    area1 = len1 * wid1;
    area2 = len2 * wid2;
    // Print the area
    cout << "First area is: " << area1 << endl;
    cout << "Second area is: " << area2 << endl;

    // Which is larger?
    if (area1 > area2) {
        cout << "The first one is larger." << endl;
    }
    else if (area2 > area1) {
        cout << "The second one is larger." << endl;
    }
    else {
        cout << "They're both the same size." << endl;
    }
    return 0;
}