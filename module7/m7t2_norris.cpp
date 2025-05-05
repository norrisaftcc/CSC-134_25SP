/*
CSC 134
M7T2 - Rectangles (From Gaddis)
norrisa
4/30/2025
Gold attempt
*/

#include <iostream>
#include "rectangle.h"
// (use "" not <> when it's your own file)
using namespace std;


// main goes here

int main() {

    double len, wid, area;

    cout << "Rectangle Calculations" << endl;
    cout << "Rectangle 1" << endl;
    cout << "enter width: ";
    cin  >> wid;
    cout << "enter length: ";
    cin  >> len;

    Rectangle r1 = Rectangle();
    r1.setWidth(wid);
    r1.setLength(len);

    cout << "The area is: " << r1.getArea() << endl;

    return 0;
}