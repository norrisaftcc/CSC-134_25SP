/*
CSC 134
M5T1 - Basic Function Calling 
norrisa
3/26/2025
*/

#include <iostream>
using namespace std;

// Purpose: Show how basic functions work

// Declare functions here, so main() knows they exist.
void show_message();

// main() here
int main() {
    cout << "Hello from main()" << endl;
    show_message(); // call the function
    // done
    return 0;
}

// Define functions here, including full body {}.
void show_message() {
    cout << "This is a message" << endl;
}
