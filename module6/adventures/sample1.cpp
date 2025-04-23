#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

// Define constants for directions
enum Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3,
    NUM_DIRECTIONS = 4
};

// Direction strings for output
const string DIRECTION_NAMES[NUM_DIRECTIONS] = {
    "north", "east", "south", "west"
};

// Define constants for rooms
enum Room {
    ENTRANCE_HALL = 0,
    LIBRARY = 1,
    KITCHEN = 2,
    GARDEN = 3,
    BASEMENT = 4,
    NUM_ROOMS = 5
};

// Item struct
struct Item {
    string name;
    string description;
};

// Function declarations
void displayRoomArt(int roomId);
void clearScreen();
void displayHelp();
string getExits(int currentRoom, const int connections[NUM_ROOMS][NUM_DIRECTIONS]);
string examineRoom();

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Room names array
    string roomNames[NUM_ROOMS] = {
        "Entrance Hall",
        "Library",
        "Kitchen",
        "Garden",
        "Basement"
    };
    
    // Room descriptions array
    string roomDescriptions[NUM_ROOMS] = {
        "A grand entrance hall with a dusty chandelier hanging above.",
        "Walls lined with ancient books. The air smells of old paper.",
        "A spacious kitchen with an old stove and wooden counter.",
        "An overgrown garden with stone pathways and a small fountain.",
        "A dark, damp basement with cobwebs in the corners."
    };
    
    // Room items
    vector<Item> roomItems = {
        {"old key", "A rusty old key that might unlock something."},
        {"dusty book", "A leather-bound book titled 'Secrets of the Mansion'."},
        {"silver spoon", "An ornate silver spoon with a family crest."},
        {"gardening gloves", "Worn leather gardening gloves."},
        {"lantern", "An old oil lantern that still works."}
    };
    
    // Adjacency list using a 2D array
    // connections[from_room][direction] = to_room or -1 if no connection
    int connections[NUM_ROOMS][NUM_DIRECTIONS];
    
    // Initialize all connections to -1 (no connection)
    for (int i = 0; i < NUM_ROOMS; i++) {
        for (int j = 0; j < NUM_DIRECTIONS; j++) {
            connections[i][j] = -1;
        }
    }
    
    // Define the connections between rooms using the Room enum
    // Entrance Hall connections
    connections[ENTRANCE_HALL][NORTH] = LIBRARY;    // Entrance Hall -> North -> Library
    connections[ENTRANCE_HALL][EAST] = KITCHEN;     // Entrance Hall -> East -> Kitchen
    connections[ENTRANCE_HALL][SOUTH] = -1;         // No connection south
    connections[ENTRANCE_HALL][WEST] = GARDEN;      // Entrance Hall -> West -> Garden
    
    // Library connections
    connections[LIBRARY][NORTH] = -1;               // No connection north
    connections[LIBRARY][EAST] = -1;                // No connection east
    connections[LIBRARY][SOUTH] = ENTRANCE_HALL;    // Library -> South -> Entrance Hall
    connections[LIBRARY][WEST] = -1;                // No connection west
    
    // Kitchen connections
    connections[KITCHEN][NORTH] = -1;               // No connection north
    connections[KITCHEN][EAST] = -1;                // No connection east
    connections[KITCHEN][SOUTH] = BASEMENT;         // Kitchen -> South -> Basement
    connections[KITCHEN][WEST] = ENTRANCE_HALL;     // Kitchen -> West -> Entrance Hall
    
    // Garden connections
    connections[GARDEN][NORTH] = -1;                // No connection north
    connections[GARDEN][EAST] = ENTRANCE_HALL;      // Garden -> East -> Entrance Hall
    connections[GARDEN][SOUTH] = -1;                // No connection south
    connections[GARDEN][WEST] = -1;                 // No connection west
    
    // Basement connections
    connections[BASEMENT][NORTH] = KITCHEN;         // Basement -> North -> Kitchen
    connections[BASEMENT][EAST] = -1;               // No connection east
    connections[BASEMENT][SOUTH] = -1;              // No connection south
    connections[BASEMENT][WEST] = -1;               // No connection west
    
    // Game state
    int currentRoom = ENTRANCE_HALL; // Start in the Entrance Hall
    bool gameRunning = true;
    vector<string> inventory;
    vector<bool> roomItemTaken(NUM_ROOMS, false);
    vector<string> gameLog;
    
    // Add welcome message to log
    gameLog.push_back("Welcome to the Haunted Mansion Adventure!");
    
    // Show title and welcome message
    clearScreen();
    cout << BOLD << MAGENTA;
    cout << "=====================================" << endl;
    cout << "=                                   =" << endl;
    cout << "=      HAUNTED MANSION ADVENTURE    =" << endl;
    cout << "=                                   =" << endl;
    cout << "=====================================" << endl;
    cout << RESET << endl;
    
    cout << WHITE << "Welcome to the Haunted Mansion Adventure!" << RESET << endl;
    cout << "Type " << CYAN << "'help'" << RESET << " at any time to see available commands." << endl;
    cout << "\nPress Enter to begin...";
    cin.get();
    
    // Game loop
    while (gameRunning) {
        // Clear screen
        clearScreen();
        
        // Display room art
        displayRoomArt(currentRoom);
        
        // Display current room information
        cout << BOLD << GREEN << "You are in the " << roomNames[currentRoom] << RESET << endl;
        cout << WHITE << roomDescriptions[currentRoom] << RESET << endl << endl;
        
        // Show available exits
        cout << CYAN << "Exits: " << getExits(currentRoom, connections) << RESET << endl;
        
        // Show item in room if not taken
        if (currentRoom < roomItems.size() && !roomItemTaken[currentRoom]) {
            cout << YELLOW << "You see a " << roomItems[currentRoom].name << " here." << RESET << endl;
        }
        
        // Display inventory
        cout << MAGENTA << "\nInventory:" << RESET << endl;
        if (inventory.empty()) {
            cout << "Your inventory is empty." << endl;
        } else {
            for (const auto& item : inventory) {
                cout << "- " << item << endl;
            }
        }
        
        // Display game log (last 5 entries)
        cout << BLUE << "\nRecent events:" << RESET << endl;
        int logStart = max(0, (int)gameLog.size() - 5);
        for (int i = logStart; i < gameLog.size(); i++) {
            cout << gameLog[i] << endl;
        }
        
        // Get player input
        string command;
        cout << "\n" << WHITE << "What would you like to do? " << RESET;
        getline(cin, command);
        
        // Convert command to lowercase
        transform(command.begin(), command.end(), command.begin(), ::tolower);
        
        // Process commands
        if (command == "north" || command == "n") {
            if (connections[currentRoom][NORTH] != -1) {
                currentRoom = connections[currentRoom][NORTH];
                gameLog.push_back("You moved north to the " + roomNames[currentRoom] + ".");
            } else {
                gameLog.push_back("You can't go that way.");
            }
        } else if (command == "east" || command == "e") {
            if (connections[currentRoom][EAST] != -1) {
                currentRoom = connections[currentRoom][EAST];
                gameLog.push_back("You moved east to the " + roomNames[currentRoom] + ".");
            } else {
                gameLog.push_back("You can't go that way.");
            }
        } else if (command == "south" || command == "s") {
            if (connections[currentRoom][SOUTH] != -1) {
                currentRoom = connections[currentRoom][SOUTH];
                gameLog.push_back("You moved south to the " + roomNames[currentRoom] + ".");
            } else {
                gameLog.push_back("You can't go that way.");
            }
        } else if (command == "west" || command == "w") {
            if (connections[currentRoom][WEST] != -1) {
                currentRoom = connections[currentRoom][WEST];
                gameLog.push_back("You moved west to the " + roomNames[currentRoom] + ".");
            } else {
                gameLog.push_back("You can't go that way.");
            }
        } else if (command == "take" || command == "t") {
            if (currentRoom < roomItems.size() && !roomItemTaken[currentRoom]) {
                inventory.push_back(roomItems[currentRoom].name);
                roomItemTaken[currentRoom] = true;
                gameLog.push_back("You picked up the " + roomItems[currentRoom].name + ".");
            } else {
                gameLog.push_back("There's nothing here to take.");
            }
        } else if (command == "examine" || command == "x") {
            string discovery = examineRoom();
            gameLog.push_back("You examine the room carefully. " + discovery);
        } else if (command == "help" || command == "h") {
            displayHelp();
            cout << "\nPress Enter to continue...";
            cin.get();
        } else if (command == "quit" || command == "q") {
            gameRunning = false;
        } else {
            gameLog.push_back("I don't understand that command.");
        }
        
        // Keep log at a reasonable size
        if (gameLog.size() > 20) {
            gameLog.erase(gameLog.begin());
        }
    }
    
    // End game message
    clearScreen();
    cout << BOLD << MAGENTA;
    cout << "=====================================" << endl;
    cout << "=                                   =" << endl;
    cout << "=         THANKS FOR PLAYING!       =" << endl;
    cout << "=                                   =" << endl;
    cout << "=====================================" << endl;
    cout << RESET << endl;
    
    return 0;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void displayHelp() {
    clearScreen();
    cout << BOLD << CYAN << "AVAILABLE COMMANDS:" << RESET << endl << endl;
    cout << BOLD << "Movement:" << RESET << endl;
    cout << "  " << CYAN << "north" << RESET << " or " << CYAN << "n" << RESET << " - Move north" << endl;
    cout << "  " << CYAN << "east" << RESET << " or " << CYAN << "e" << RESET << " - Move east" << endl;
    cout << "  " << CYAN << "south" << RESET << " or " << CYAN << "s" << RESET << " - Move south" << endl;
    cout << "  " << CYAN << "west" << RESET << " or " << CYAN << "w" << RESET << " - Move west" << endl;
    cout << endl;
    cout << BOLD << "Actions:" << RESET << endl;
    cout << "  " << CYAN << "take" << RESET << " or " << CYAN << "t" << RESET << " - Take an item in the current room" << endl;
    cout << "  " << CYAN << "examine" << RESET << " or " << CYAN << "x" << RESET << " - Examine the current room more closely" << endl;
    cout << "  " << CYAN << "help" << RESET << " or " << CYAN << "h" << RESET << " - Display this help menu" << endl;
    cout << "  " << CYAN << "quit" << RESET << " or " << CYAN << "q" << RESET << " - Quit the game" << endl;
}

string getExits(int currentRoom, const int connections[NUM_ROOMS][NUM_DIRECTIONS]) {
    string exits = "";
    bool hasExits = false;
    
    for (int dir = 0; dir < NUM_DIRECTIONS; dir++) {
        if (connections[currentRoom][dir] != -1) {
            if (hasExits) {
                exits += ", ";
            }
            exits += DIRECTION_NAMES[dir];
            hasExits = true;
        }
    }
    
    if (!hasExits) {
        exits = "none";
    }
    
    return exits;
}

string examineRoom() {
    // Random discoveries when examining a room
    vector<string> discoveries = {
        "You find nothing of interest.",
        "The walls have strange markings on them.",
        "There's a draft coming from somewhere.",
        "You hear faint whispers but can't locate the source.",
        "The floor has scratches as if something was dragged.",
        "A shadow moves across the wall, but there's nothing to cast it.",
        "The temperature suddenly drops for a moment.",
        "You notice a strange smell that quickly disappears.",
        "Something skitters behind a piece of furniture.",
        "You feel like you're being watched."
    };
    
    int randomIndex = rand() % discoveries.size();
    return discoveries[randomIndex];
}

void displayRoomArt(int roomId) {
    switch (roomId) {
        case ENTRANCE_HALL:
            cout << YELLOW;
            cout << "    +-------------+" << endl;
            cout << "    |             |" << endl;
            cout << "    |   ENTRANCE  |" << endl;
            cout << "    |     HALL    |" << endl;
            cout << "    |             |" << endl;
            cout << "    +-------------+" << endl;
            cout << RESET << endl;
            break;
        case LIBRARY:
            cout << BLUE;
            cout << "    +-------------+" << endl;
            cout << "    | [=] [=] [=] |" << endl;
            cout << "    |  LIBRARY    |" << endl;
            cout << "    | [=] [=] [=] |" << endl;
            cout << "    |             |" << endl;
            cout << "    +-------------+" << endl;
            cout << RESET << endl;
            break;
        case KITCHEN:
            cout << CYAN;
            cout << "    +-------------+" << endl;
            cout << "    |  __    __   |" << endl;
            cout << "    | |__|  |__|  |" << endl;
            cout << "    |  KITCHEN    |" << endl;
            cout << "    |             |" << endl;
            cout << "    +-------------+" << endl;
            cout << RESET << endl;
            break;
        case GARDEN:
            cout << GREEN;
            cout << "    +-------------+" << endl;
            cout << "    | *  *  *  *  |" << endl;
            cout << "    |  GARDEN  *  |" << endl;
            cout << "    | *  *  *  *  |" << endl;
            cout << "    |   *   *   * |" << endl;
            cout << "    +-------------+" << endl;
            cout << RESET << endl;
            break;
        case BASEMENT:
            cout << RED;
            cout << "    +-------------+" << endl;
            cout << "    | \\/\\/\\/\\/\\/\\/ |" << endl;
            cout << "    |  BASEMENT   |" << endl;
            cout << "    | /\\/\\/\\/\\/\\/\\ |" << endl;
            cout << "    |             |" << endl;
            cout << "    +-------------+" << endl;
            cout << RESET << endl;
            break;
    }
}