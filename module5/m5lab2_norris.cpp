// M5LAB2
// CSC 134
// norrisa
// 4/2/25

#include <iostream>
using namespace std;

// Declare (Write the prototypes for)
// the getLength,
// getWidth, getArea, and displayData
// functions here.
double getLength();

int main()
{
	// This program calculates the area of a rectangle.
	// TODO: fix any syntax errors
	
   double length,    // The rectangle's length
          width,     // The rectangle's width
          area;      // The rectangle's area
          
   // Get the rectangle's length.
   length = getLength();
   // Get the rectangle's width.
   //width = getWidth()
   // Get the rectangle's area.
   //are = getArea();
   
   // Display the rectangle's data.
   //displayData(length, width, area);
          
   return 0;
}

//***************************************************
// TODO: write the getLength, getWidth, getArea,    *
// and displayData functions below.                 *
//***************************************************
double getLength() {
   // Ask the user for the length, then return it
	return 5.0;
}