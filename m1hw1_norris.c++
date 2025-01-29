// CSC 134
// M1HW1 - a big homework (for you)
// norrisa
// 1/29/25

#include <iostream>
using namespace std;


int main() {
    // setup
    string movie_name = "The Dark Knight Rises";
    string director = "Christopher Nolan";                      // bravo
    int year = 2012;
    double box_office = 1.115;                       // billion $

    // output
    cout << "The movie " << movie_name << " came out in " << year << "." << endl;
    cout << "The director was " << director << "." << endl;
    cout << "Box office was $" << box_office << " billion USD." << endl;

    cout << "The Plane Scene" << endl;
    cout << "CIA : If I pull that off, will you die?" << endl;
    cout << "Bane: It would be extremely painful..." << endl;
    cout << "CIA : You're a big guy." << endl;
    cout << "Bane: ... for you." << endl;
    cout << endl;
    return 0; // done
}