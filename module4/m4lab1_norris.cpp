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
    string pixel = "🔥"; // use any one character or an emoji
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
    for (int i = 0; i < 10; i++) {
        cout << pixel << " ";
    }
    cout << endl;
}