#include <iostream>
#include "Graph.h"
// you should replace the above line with 
// #include "StringGraph.h"
// if you wish to use graphs with string data


using namespace std;

int main() {
// Changes by Copilot.
/*
prompt: What I would like you to do is: Create one of these maps using this code technique. Here's an example. Weights should be the number of "steps" neeed on the map. You only need to connect, say, three or four important locations.

*/
// Create a new Graph object for the Super Mario World Level 1 map
Graph marioMap;

// Add vertices representing key locations on the map
Vertex* start      = marioMap.AddVertex("Start");
Vertex* yoshiHouse = marioMap.AddVertex("Yoshi's House");
Vertex* donutPlains = marioMap.AddVertex("Donut Plains");
Vertex* castle     = marioMap.AddVertex("Castle");

// Add undirected edges with weights equal to the number of steps required
marioMap.AddUndirectedEdge(start, yoshiHouse, 5);      // 5 steps from Start to Yoshi's House
marioMap.AddUndirectedEdge(yoshiHouse, donutPlains, 8);  // 8 steps from Yoshi's House to Donut Plains
marioMap.AddUndirectedEdge(donutPlains, castle, 12);     // 12 steps from Donut Plains to Castle
marioMap.AddUndirectedEdge(start, castle, 20);           // 20 steps for a direct (but longer) route from Start to Castle

    
   // Show the graph's vertices and edges
   for (Vertex* vertex : marioMap.GetVertices()) {
      cout << "Location: " << vertex->label << endl;
        
      // Show outgoing edges (flights from location)
      cout << "  Trips from " << vertex->label << ":" << endl;
      for (Edge* outgoingEdge : *marioMap.GetEdgesFrom(vertex)) {
         cout << "   - " << vertex->label << " to ";
         cout << outgoingEdge->toVertex->label << ", ";
         cout << (int)outgoingEdge->weight << " steps" << endl;
      }
     
      // Show incoming edges (flights to location)
      cout << "  Trips to " << vertex->label << ":" << endl;
      for (Edge* incomingEdge : *marioMap.GetEdgesTo(vertex)) {
         cout << "   - " << incomingEdge->fromVertex->label << " to ";
         cout << vertex->label << ", ";
         cout << (int)incomingEdge->weight << " steps" << endl;
      }
   }
    
   return 0;
}