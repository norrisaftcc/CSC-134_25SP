#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Global variables for character stats
int strength, dexterity, constitution, intelligence, wisdom, charisma;
string name, char_class;
int level, hp;


// Function prototypes (declarations)
void inputStats();
void displayCharacter();
void saveCharacter();
int rollDice();
int rollStat();

int main() {
    srand(time(0)); // seed our RNG
    cout << "Character creation" << endl;
    inputStats();
    displayCharacter();
    cout << "Type 'a' to accept, 'r' to reroll." << endl;
    char choice;
    cin >> choice;
    while (choice == 'r') {
        inputStats();
        displayCharacter();
        cout << "Type 'a' to accept, 'r' to reroll." << endl;
        cin >> choice;
    }
    return 0;
}

// Function definition (the full version)
void inputStats() {
    cout << "Rolling your character..." << endl;
    strength = rollStat();
    dexterity = rollStat();
    constitution = rollStat();
    intelligence = rollStat();
    wisdom = rollStat();
    charisma = rollStat();
}

void displayCharacter() {
    cout << "\nCharacter Stats:\n";
    cout << "Strength: " << strength << endl;
    cout << "Dexterity: " << dexterity << endl;
    cout << "Constitution: " << constitution << endl;
    cout << "Intelligence: " << intelligence << endl;
    cout << "Wisdom: " << wisdom << endl;
    cout << "Charisma: " << charisma << endl;
}

void saveCharacter() {
    // TODO
}

int rollDice() {
    return rand() % 6 + 1;
}

int rollStat() {
    // roll 3d6
    int stat;
    stat = rollDice() + rollDice() + rollDice();
    return stat;
}