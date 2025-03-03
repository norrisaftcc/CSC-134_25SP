// CSC 134
// M3LAB2 - Letter Grade 
// norrisa
// 2/26/2026

#include <iostream>
using namespace std;

int main() {
    // Define variables
    int num_grade;                  // 0-100
    string letter_grade;            // "A", "B", etc.
    const int A_PLUS= 100;          // this grade, or higher
    const int A     = 90;
    const int B     = 80;
    const int C     = 70;
    const int D     = 60;
    const int F     = 0;

    // ask for the number grade
    cout << "Number grade to letter grade conversion program." << endl;
    cout << "Enter the number grade: ";
    cin >> num_grade;
    // find the letter grade
    // remember && is AND
    // and || is OR
    if (num_grade >= A_PLUS) {
        letter_grade = "A+";
    }
    if (num_grade >= A && num_grade < A_PLUS) {
        letter_grade = "A";
    }
    if (num_grade >= B && num_grade < A) {
        letter_grade = "B";
    }
    if (num_grade >= C && num_grade < B) {
        letter_grade = "C";
    }
    if (num_grade >= D && num_grade < C) {
        letter_grade = "D";
    }
    if (num_grade >= F && num_grade < D) {
        letter_grade = "F";
    }

    // tell user the answer
    cout << "The grade " << num_grade << " is a " << letter_grade << endl;


}