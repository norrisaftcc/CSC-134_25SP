/*
CSC 134
M4LAB1 - for loops
norrisa
3/17/2025
draw a box of characters several different ways
*/
#include <iostream>
using namespace std;

int main() {
    // New info discovered:
    // any regular character can be char
    // but Unicode characters have to be strings
    string pixel = "👾"; // use any one character or an emoji
    const int WIDTH = 8;
    const int HEIGHT = 5;
    // cout << pixel << endl;

    // three ways to run a loop
    // 1. while loop
    int count = 0;
    while (count < 5) {
        cout << pixel;
        count++;
    }
    cout << endl;
    // 2. do while loop
    count = 0;
    do {
        cout << pixel << " ";
        count++;
    } while (count < 5);
    // 3. for loop
    // This is the one time using i as a variable name is ok
    // i stands for index
    cout << endl;
    cout << pixel << " printed horizontally (row)" << endl;
    for (int i = 0; i < WIDTH; i++) {
        cout << pixel << " ";
    }
    cout << endl;
    cout << pixel << " printed vertically (column)" << endl;
    for (int i = 0; i < HEIGHT; i++) {
        cout << pixel << endl;
    }
    cout << endl << "Printing a box " << WIDTH << " by " << HEIGHT << endl;
    // this is a nested loop
    // for each row
    for (int h=0; h<HEIGHT; h++) {
        // print the current row
        for (int w=0; w<WIDTH; w++) {
            cout << pixel << " ";
        }
        // go to the next line
        cout << endl;
    }
    // just for fun: extra user validation
    int width, height; // both must be > 0
    bool good_input = false;
    do {
        cout >> "Enter width: ";
        cin << width;
        cout >> "Enter height: ";
        cin << height;
        if (width > 0 && height > 0) {
            good_input = true;
        }
        else {
            cout << "Please enter nonzero width and height" << endl;
        }
    } while (good_input == false); // repeat until we have valid data

    
}