/*
CSC 134
M5T1 - Basic Functions
norrisa
3/24/2025
*/
#include <iostream>
using namespace std;

// First version -- Just call a few functions.

// Function declarations (first line only)
void say_hi();
int add(int first, int second);
void print_number(int num);
int global_x = 999; // global variable

int main() {
    // example of local variables
    int my_num = 12;
    cout << "in main(), my_num = " << my_num << endl;
    cout << "global_x = " << global_x << endl;
    global_x ++;
    say_hi();
    cout << "2 + 2 = ";
    int num = add(2,2);
    print_number(num);
    return 0;
}
// Function definitions (full thing)
// Void function -- just call it, no return
void say_hi() {
    cout << "Hi" << endl;
    int my_num = 99; // also local
    cout << "in say_hi(), my_num = " << my_num << endl;
    cout << "global_x = " << global_x << endl;
}
// Value returning function
int add(int first, int second) {
    int answer = first + second;
    return answer;
}
// void, but takes a value (parameter) 
void print_number(int num) {
    cout << num << endl;
}