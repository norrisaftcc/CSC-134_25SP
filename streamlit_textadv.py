import streamlit as st
import random
from PIL import Image
import io

# Define constants for directions
NORTH = 0
EAST = 1
SOUTH = 2
WEST = 3
NUM_DIRECTIONS = 4

# Direction strings for output
DIRECTION_NAMES = ["north", "east", "south", "west"]

# Define constants for rooms
ENTRANCE_HALL = 0
LIBRARY = 1
KITCHEN = 2
GARDEN = 3
BASEMENT = 4
NUM_ROOMS = 5

def initialize_game_state():
    """Initialize the game state if it doesn't exist yet."""
    if 'current_room' not in st.session_state:
        st.session_state.current_room = ENTRANCE_HALL
    
    if 'inventory' not in st.session_state:
        st.session_state.inventory = []
    
    if 'game_log' not in st.session_state:
        st.session_state.game_log = ["Welcome to the Haunted Mansion Adventure!"]
    
    if 'found_items' not in st.session_state:
        st.session_state.found_items = set()

def reset_game():
    """Reset the game state."""
    st.session_state.current_room = ENTRANCE_HALL
    st.session_state.inventory = []
    st.session_state.game_log = ["Welcome to the Haunted Mansion Adventure!"]
    st.session_state.found_items = set()

def main():
    st.title("Haunted Mansion Adventure")
    
    # Initialize game state
    initialize_game_state()
    
    # Define room names
    room_names = [
        "Entrance Hall",
        "Library",
        "Kitchen",
        "Garden",
        "Basement"
    ]
    
    # Room descriptions
    room_descriptions = [
        "A grand entrance hall with a dusty chandelier hanging above.",
        "Walls lined with ancient books. The air smells of old paper.",
        "A spacious kitchen with an old stove and wooden counter.",
        "An overgrown garden with stone pathways and a small fountain.",
        "A dark, damp basement with cobwebs in the corners."
    ]
    
    # Room items - add some items to discover
    room_items = [
        {"name": "old key", "description": "A rusty old key that might unlock something."},
        {"name": "dusty book", "description": "A leather-bound book titled 'Secrets of the Mansion'."},
        {"name": "silver spoon", "description": "An ornate silver spoon with a family crest."},
        {"name": "gardening gloves", "description": "Worn leather gardening gloves."},
        {"name": "lantern", "description": "An old oil lantern that still works."}
    ]
    
    # Initialize the connections between rooms
    connections = [[-1 for _ in range(NUM_DIRECTIONS)] for _ in range(NUM_ROOMS)]
    
    # Entrance Hall connections
    connections[ENTRANCE_HALL][NORTH] = LIBRARY
    connections[ENTRANCE_HALL][EAST] = KITCHEN
    connections[ENTRANCE_HALL][SOUTH] = -1
    connections[ENTRANCE_HALL][WEST] = GARDEN
    
    # Library connections
    connections[LIBRARY][NORTH] = -1
    connections[LIBRARY][EAST] = -1
    connections[LIBRARY][SOUTH] = ENTRANCE_HALL
    connections[LIBRARY][WEST] = -1
    
    # Kitchen connections
    connections[KITCHEN][NORTH] = -1
    connections[KITCHEN][EAST] = -1
    connections[KITCHEN][SOUTH] = BASEMENT
    connections[KITCHEN][WEST] = ENTRANCE_HALL
    
    # Garden connections
    connections[GARDEN][NORTH] = -1
    connections[GARDEN][EAST] = ENTRANCE_HALL
    connections[GARDEN][SOUTH] = -1
    connections[GARDEN][WEST] = -1
    
    # Basement connections
    connections[BASEMENT][NORTH] = KITCHEN
    connections[BASEMENT][EAST] = -1
    connections[BASEMENT][SOUTH] = -1
    connections[BASEMENT][WEST] = -1
    
    # Display current room info
    current_room = st.session_state.current_room
    
    # Display ASCII art for each room
    room_art = generate_room_art(current_room)
    st.text(room_art)
    
    # Display room information
    st.header(f"You are in the {room_names[current_room]}")
    st.write(room_descriptions[current_room])
    
    # Show available exits
    exits = []
    for direction in range(NUM_DIRECTIONS):
        if connections[current_room][direction] != -1:
            exits.append(DIRECTION_NAMES[direction])
    
    st.write("Exits: " + ", ".join(exits) if exits else "none")
    
    # Show item in room if not collected yet
    if current_room < len(room_items) and room_items[current_room]["name"] not in st.session_state.found_items:
        st.info(f"You see a {room_items[current_room]['name']} here.")
    
    # Display inventory
    if st.session_state.inventory:
        st.sidebar.header("Inventory")
        for item in st.session_state.inventory:
            st.sidebar.write(f"- {item}")
    else:
        st.sidebar.header("Inventory")
        st.sidebar.write("Your inventory is empty.")
    
    # Display game log
    st.sidebar.header("Game Log")
    for log_entry in reversed(st.session_state.game_log[-5:]):
        st.sidebar.write(log_entry)
    
    # Create buttons for movement
    st.write("Where would you like to go?")
    
    col1, col2, col3, col4 = st.columns(4)
    
    # Display directional buttons
    with col1:
        if "north" in exits:
            if st.button("Go North"):
                st.session_state.current_room = connections[current_room][NORTH]
                st.session_state.game_log.append(f"You moved north to the {room_names[connections[current_room][NORTH]]}.")
                st.experimental_rerun()
        else:
            st.button("Go North", disabled=True)
    
    with col2:
        if "east" in exits:
            if st.button("Go East"):
                st.session_state.current_room = connections[current_room][EAST]
                st.session_state.game_log.append(f"You moved east to the {room_names[connections[current_room][EAST]]}.")
                st.experimental_rerun()
        else:
            st.button("Go East", disabled=True)
    
    with col3:
        if "south" in exits:
            if st.button("Go South"):
                st.session_state.current_room = connections[current_room][SOUTH]
                st.session_state.game_log.append(f"You moved south to the {room_names[connections[current_room][SOUTH]]}.")
                st.experimental_rerun()
        else:
            st.button("Go South", disabled=True)
    
    with col4:
        if "west" in exits:
            if st.button("Go West"):
                st.session_state.current_room = connections[current_room][WEST]
                st.session_state.game_log.append(f"You moved west to the {room_names[connections[current_room][WEST]]}.")
                st.experimental_rerun()
        else:
            st.button("Go West", disabled=True)
    
    # Action buttons
    st.write("Actions:")
    col1, col2 = st.columns(2)
    
    with col1:
        # Take item button
        if current_room < len(room_items) and room_items[current_room]["name"] not in st.session_state.found_items:
            if st.button(f"Take {room_items[current_room]['name']}"):
                item_name = room_items[current_room]["name"]
                st.session_state.inventory.append(item_name)
                st.session_state.found_items.add(item_name)
                st.session_state.game_log.append(f"You picked up the {item_name}.")
                st.experimental_rerun()
    
    with col2:
        # Examine room button
        if st.button("Examine Room"):
            # Chance to find something interesting
            discoveries = [
                "You find nothing of interest.",
                "The walls have strange markings on them.",
                "There's a draft coming from somewhere.",
                "You hear faint whispers but can't locate the source.",
                "The floor has scratches as if something was dragged."
            ]
            discovery = random.choice(discoveries)
            st.session_state.game_log.append(f"You examine the room carefully. {discovery}")
            st.experimental_rerun()
    
    # Reset game button
    if st.button("Reset Game"):
        reset_game()
        st.experimental_rerun()

def generate_room_art(room_id):
    """Generate ASCII art for each room"""
    art = ""
    
    if room_id == ENTRANCE_HALL:
        art = """
    +-------------+
    |             |
    |   ENTRANCE  |
    |     HALL    |
    |             |
    +-------------+
        """
    elif room_id == LIBRARY:
        art = """
    +-------------+
    | [=] [=] [=] |
    |  LIBRARY    |
    | [=] [=] [=] |
    |             |
    +-------------+
        """
    elif room_id == KITCHEN:
        art = """
    +-------------+
    |  __    __   |
    | |__|  |__|  |
    |  KITCHEN    |
    |             |
    +-------------+
        """
    elif room_id == GARDEN:
        art = """
    +-------------+
    | *  *  *  *  |
    |  GARDEN  *  |
    | *  *  *  *  |
    |   *   *   * |
    +-------------+
        """
    elif room_id == BASEMENT:
        art = """
    +-------------+
    | \\/\\/\\/\\/\\/\\/ |
    |  BASEMENT   |
    | /\\/\\/\\/\\/\\/\\ |
    |             |
    +-------------+
        """
    
    return art

if __name__ == "__main__":
    main()
