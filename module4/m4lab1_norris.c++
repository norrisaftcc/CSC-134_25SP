/*
CSC 134
M4LAB1 - Grid with loops
norrisa
3/17/2025
nested loops
*/
#include <iostream>
using namespace std;

int main() {
    string pattern = "🌿🌱"; 
    //string pattern = "💀🔥";
    const int WIDTH = 8;
    const int HEIGHT = 5;
    // while loop version
    int count = 0;
    while (count < WIDTH) {
        cout << pattern;
        count++;
    }
    cout << endl;

    // print a row (horizontal)
    cout << "row" << endl;
    for (int i=0; i < WIDTH; i++) {
        cout << pattern;
    }
    cout << endl;
    // print a column (vertical)
    cout << "column" << endl;
    for (int i=0; i < HEIGHT; i++) {
        cout << pattern << endl;
    }
    // print a square (combine both)
    // TODO: ask the user
    int width, height;
    bool good_values = false;
    do {
        cout << "Enter width and height, both >0" << endl;
        cin >> width >> height;
        if (width > 0 && height > 0) {
            good_values = true;
        }
        else {
            cout << "Width and height must be >0" << endl;
        }

    } while (good_values == false); // loop until we get good values!

    cout << "Square of " << width << " by " << height << endl;
    for (int v=0; v< height; v++) {
        // print one row
        for (int h=0; h< height; h++) {
            cout << pattern;
        }
        cout << endl; // go to next row
    }

}