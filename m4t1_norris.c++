// CSC 134
// M4T1 - While Loops
// norrisa
// 3/10/2025

#include <iostream>
using namespace std;
  
int main()
{
    // Part 1 - Just count five times
    int count = 1;
    while (count <= 5) {
        cout << "Hello #" << count << endl;
        //count = count + 1;
        //count += 1;
        count++; // all do the same thing
    }
    cout << "Finished!" << endl;

    // Part 2 - Table of Squares
    const int MIN_NUM = 1;
    const int MAX_NUM = 10;
    int num = MIN_NUM;
    
    while (num <= MAX_NUM) {
        cout << num << endl;
        num = num + 1;
    }

    return 0;
}