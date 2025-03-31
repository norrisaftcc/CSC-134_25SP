#include <iostream>
using namespace std;

/*
CSC 134
M5LAB1 - Choose Your Own Adventure
norrisa, 0001
3/31/2025
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
void main_menu();
void choice_front_door();
void choice_back_door();
void choice_go_home();
// TODO: add more choices here
void choice_warrior();
void choice_wizard();
void choice_nothing();

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
  cout << "You're in front of a spooky old house..." << endl;
  cout << "Do you:" << endl;
  cout << "1. Try the front door" << endl;
  cout << "2. Sneak around back" << endl;
  cout << "3. Forget it, and go home" << endl;
  cout << "4. [Quit]" << endl;
  cout << "Choose: ";
  int choice;
  cin >> choice;
  if (1 == choice) {
    choice_front_door();
  } else if (2 == choice) {
    // call choice 2 here
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
void choice_front_door() {
  cout << "Try the front door." << endl;
  cout << "It's locked. " << endl;
  cout << "Do you:" << endl;
  cout << "1. Check around back" << endl;
  cout << "2. Give up and go home" << endl;
  int choice;
  cout << "Choose: ";
  cin >> choice;
  if (1 == choice) {
    choice_back_door();
  } else if (2 == choice) {
    choice_go_home();
  }
}

void choice_back_door() { 
    cout << "TODO: Write something here" << endl; 
}

void choice_go_home() { 
    cout << "On the way home..." << endl;
    cout << "🚚 ... 💥" << endl;
    cout << "You wake up in a mysterious land." << endl;
    cout << "Do you:" << endl;
    cout << "1. Learn the sword and become a 🤺 Warrior" << endl;
    cout << "2. Learn magic and become a 🧙 Wizard" << endl;
    cout << "3. Decide it's all just a dream, and wait to wake up" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        choice_warrior();
    }
    else if (choice ==2) {
        choice_wizard();
    }
    else if (choice ==3) {
        choice_nothing();
    }
}

// any new choices go here
void choice_warrior() {
    cout << "You become a successful warrior" << endl;
    cout << "***GOOD END***" << endl;
}

void choice_wizard() {
    cout << "You become a mysterious wizard" << endl;
    cout << "***GOOD END***" << endl;
}

void choice_nothing() {
    cout << "Unfortunately, when the Dark Wizard attacks, you're still just hanging out" << endl;
    cout << "***BAD END -- you have died ***" << endl;
}