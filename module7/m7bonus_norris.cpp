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
// Create a new Graph object for a Simplified Subway System
Graph subwayMap;

// Add vertices representing subway stations
Vertex* centralStation = subwayMap.AddVertex("Central Station");
Vertex* marketSquare = subwayMap.AddVertex("Market Square");
Vertex* universityStop = subwayMap.AddVertex("University");
Vertex* parkDistrict = subwayMap.AddVertex("Park District");
Vertex* sportsDome = subwayMap.AddVertex("Sports Dome");
Vertex* riverfront = subwayMap.AddVertex("Riverfront");

// Add edges with weights representing travel time in minutes
subwayMap.AddUndirectedEdge(centralStation, marketSquare, 4);     // 4 minutes between Central and Market
subwayMap.AddUndirectedEdge(centralStation, universityStop, 6);   // 6 minutes between Central and University
subwayMap.AddUndirectedEdge(centralStation, parkDistrict, 5);     // 5 minutes between Central and Park
subwayMap.AddUndirectedEdge(marketSquare, universityStop, 3);     // 3 minutes between Market and University
subwayMap.AddUndirectedEdge(marketSquare, sportsDome, 8);         // 8 minutes between Market and Sports Dome
subwayMap.AddUndirectedEdge(universityStop, parkDistrict, 4);     // 4 minutes between University and Park
subwayMap.AddUndirectedEdge(parkDistrict, riverfront, 7);         // 7 minutes between Park and Riverfront
subwayMap.AddUndirectedEdge(sportsDome, riverfront, 6);           // 6 minutes between Sports Dome and Riverfront
    
   // Show the graph's vertices and edges
   for (Vertex* vertex : subwayMap.GetVertices()) {
      cout << "Location: " << vertex->label << endl;
        
      // Show outgoing edges (flights from location)
      cout << "  Trips from " << vertex->label << ":" << endl;
      for (Edge* outgoingEdge : *subwayMap.GetEdgesFrom(vertex)) {
         cout << "   - " << vertex->label << " to ";
         cout << outgoingEdge->toVertex->label << ", ";
         cout << (int)outgoingEdge->weight << " stops" << endl;
      }
     
      // Show incoming edges (flights to location)
      cout << "  Trips to " << vertex->label << ":" << endl;
      for (Edge* incomingEdge : *subwayMap.GetEdgesTo(vertex)) {
         cout << "   - " << incomingEdge->fromVertex->label << " to ";
         cout << vertex->label << ", ";
         cout << (int)incomingEdge->weight << " stops" << endl;
      }
   }
    
   return 0;
}