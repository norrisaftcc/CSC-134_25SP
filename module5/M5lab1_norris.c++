/*
M5LAB1
Sample CYOA
norris
3/26/25
*/

#include <iostream>
#include <limits>
using namespace std;

/*
CSC 134
M5LAB1 - Choose Your Own Adventure
[name]
[date]
This template serves as a starting point
for your own program. We'll be using
void functions to tell a simple story,
where the user gets to make choices.

You can fork this template by clicking on the name above, then click the three
dots on the top right, and click 'fork repl'. This makes a copy for you to use.
*/

// Function Prototypes
// Any functions you make will need to
// be listed here, in this format, at the top.
// This is so the compiler knows to save
// room for them in the final program.
int get_choice(int size);
void main_menu();
void choice_forest_friends();
void choice_forest_sneak();
void choice_go_home();
// TODO: add more choices here

int main() {
  cout << "M5LAB1 - Choose Your Own Adventure" << endl;
  // load up the main menu
  main_menu();
  // when we return here, we're done
  cout << "Thanks for playing!" << endl;
  return 0; // finished with no errors
}

void main_menu() {
  // Write a simple menu that lets the user choose 1,2, or 3, or 4 to quit.
  cout << "Main Menu" << endl;
  cout << "You were isekai'ed by an Amazon truck and now you're in a forest..." << endl;
  cout << "Do you:" << endl;
  cout << "1. Go look for friends" << endl;
  cout << "2. Sneak around for food and shelter" << endl;
  cout << "3. Close your eyes and wish yourself home" << endl;
  cout << "4. [Quit]" << endl;
  cout << "Choose: ";
  int choice;
  choice = get_choice(4); // 4 choices here
  if (1 == choice) {
    choice_forest_friends();
  } else if (2 == choice) {
    choice_forest_sneak();
  } else if (3 == choice) {
    choice_go_home();
  } else if (4 == choice) {
    cout << "Ok, quitting game" << endl;
    return; // go back to main()
  } else {
    cout << "That's not a valid choice, please try again." << endl;
    cin.ignore(); // clear the user input
    main_menu();  // try again
  }
}

// FUNCTION DEFINITIONS
// OK, we have the prototypes at the top, but
// now we have to actually write the functions.
// They go here, after main().
void choice_forest_friends() {
  cout << "Try the front door." << endl;
  cout << "It's locked. " << endl;
  cout << "Do you:" << endl;
  cout << "1. Check around back" << endl;
  cout << "2. Give up and go home" << endl;
  int choice;
  cout << "Choose: ";
  cin >> choice;
  if (1 == choice) {
    choice_forest_sneak();
  } else if (2 == choice) {
    choice_go_home();
  }
}

void choice_forest_sneak() { 
  cout << "TODO: Write something here" << endl; 
}

void choice_go_home() { 
    cout << "You close your eyes and say 'there's no place like home'" << endl; 
    cout << "The goblins that show up soon eat well tonight!" << endl;
    cout << "***GAME OVER***" << endl;
}

// any new choices go here
int get_choice(int size) {
  // Only allow choices between 1 and size
  int choice=0;
  while (choice < 1 || choice > size) {
    cout << "Choose: ";
    cin >> choice;
        // Check if the input is valid
        if (cin.fail()) {
          cin.clear(); // Clear the error flag
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
          cout << "Invalid input. Please enter a number between 1 and " << size << "." << endl;
        }
  }
  cout << "You picked option #" << choice << endl;
  return choice;
}