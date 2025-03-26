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
void greet_user(string name);
int double_a_number(int number);

// main() here
int main() {
    cout << "Hello from main()" << endl;
    show_message(); // call the function
    string user = "Bob";
    greet_user(user); // we're passing the value "Bob", not the actual variable
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    int answer = double_a_number(num);
    cout << "Double that is " << answer << endl;
    return 0;
}

// Define functions here, including full body {}.
void show_message() {
    cout << "This is a message." << endl;
}
void greet_user(string name) {
    cout << "Hello, " << name << endl;
}
int double_a_number(int number) {
    int answer = number * 2;
    return answer; // must return an int
}