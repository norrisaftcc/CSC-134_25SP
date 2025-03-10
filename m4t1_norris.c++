// CSC 134
// M4T1 - While Loops
// norrisa
// 3/10/2025

#include <iostream>
#include <fstream>
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
    // Let's also write it to a file
    // requires #include <fstream>
    const int MIN_NUM = 1;
    const int MAX_NUM = 10;
    int num = MIN_NUM;
    unsigned long sq; // holds a much bigger number
    string filename = "squares.txt";
    // open the file
    ofstream outfile(filename); // this replaces cout
    if (false == outfile.is_open()) {
        cout << "Error: could not open " << filename << endl;
        return -1; // error
    }

    // write the table to file
    outfile << "Table of Squares" << endl;
    outfile << "----------------" << endl;
    while (num <= MAX_NUM) {
        sq = num * num;
        outfile << num << "\t" << sq << endl;
        num = num + 1;
    }
    // close the file
    outfile.close();
    return 0;
}