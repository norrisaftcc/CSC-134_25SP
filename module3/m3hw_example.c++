// CSC 134
// M3HW - example of organization
// norrisa
// 3/5/25

#include <iostream>
using namespace std;

// Function prototypes (declarations)
// Like a table of contents or glossary
// Just the description, no code
// This is a "method signature" or a "function declaration"
void question1();
void question2();

// main
int main() {
    cout << "Example of HW" << endl;
    cout << "1. Question 1" << endl;
    cout << "2. Question 2" << endl;
    cout << "0. Exit" << endl;
    int choice;
    cin >> choice;
    if (1==choice) {
        question1();
    }
    else if (2==choice) {
        question2();
    }
    else if (0==choice) {
        cout << "Bye!" << endl;
        return 0;
    }
    else {
        cout << "Not a valid choice." << endl;
    }
    return 0; 
}

// Function definitions
// Like a dictionary -- name, and then all the code
void question1() {
    int age = 25;
    cout << "Question 1 goes here" << endl;
}

void question2() {
    int age = 30;
    cout << "Question 2 goes here" << endl;
}