#include <iostream>
using namespace std;

// Global variables for character stats
int strength, dexterity, constitution, intelligence, wisdom, charisma;

// Function prototypes
void inputStats();
void displayCharacter();

int main() {
    inputStats();
    displayCharacter();
    return 0;
}

void inputStats() {
    cout << "Enter Strength: ";
    cin >> strength;
    cout << "Enter Dexterity: ";
    cin >> dexterity;
    cout << "Enter Constitution: ";
    cin >> constitution;
    cout << "Enter Intelligence: ";
    cin >> intelligence;
    cout << "Enter Wisdom: ";
    cin >> wisdom;
    cout << "Enter Charisma: ";
    cin >> charisma;
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