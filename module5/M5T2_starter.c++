// CSC 134
// M5T2
// name
// 3/24/2025
#include <iostream>
using namespace std;

int find_square(int num);
void print_line(int number, int square);

int main() {
    // Example: print squares from 1 to 10
    for (int num=1; num<=10; num++) {
        int square = find_square(num);
        print_line(num, square);
    }
}

int find_square(int number) {
    int answer = number * number;
    return answer;
}

void print_line(int number, int square) {
    // looks like:
    cout << "Number = " << number << "\tSquare = " << square << endl;

}