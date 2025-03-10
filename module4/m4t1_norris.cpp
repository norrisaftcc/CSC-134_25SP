// CSC 134
// M4T1 - While
// norrisa
// 3/10/2025


#include <iostream>
using namespace std;
  
int main()
{

    // Part 1, just say "hi" five times
    int count = 1;
    while (count <= 5) {
        cout << "Hello number " << count << endl;
        //count = count + 1; 
        //count += 1;
        count++; // same as above
    }
    cout << "Done!" << endl;
    // part 2
    /*
    for (int i=1; i <= 10; i++) {
        cout << "Happy Mar" << i << endl;
    }
    */
   const int MIN_NUM = 1;
   const int MAX_NUM = 10;
   cout << "Table of Squares" << endl;
   cout << "----------------" << endl;
   int num = MIN_NUM;
   int sq; // num squared
   while (num <= MAX_NUM) {
    sq = num * num;
    cout << num << "\t" << sq << endl;
    num = num + 1;
   }

   // OPTIONAL: Example 3
   bool is_valid = false;
   int choice;
   while (is_valid == false) {
        cout << "Press 1 or 2 to finish." << endl;
        cin >> choice;
        if (choice == 1) {
            cout << "You picked 1" << endl;
            is_valid = true;
        }
        else if (choice == 2) {
            cout << "You picked 2" << endl;
            is_valid = true;
        }
        else {
            cout << "Sorry, not valid. Try again." << endl;
        }
   }
   cout << "Goodbye" << endl;

    return 0; // done
}
