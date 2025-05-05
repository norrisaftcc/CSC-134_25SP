#include <iostream>
#include "Graph.h"
// you should replace the above line with 
// #include "StringGraph.h"
// if you wish to use graphs with string data


using namespace std;

int main() {
   // Create a new Graph object
   Graph graph1;
    
   // Add vertices and edges representing plane flights
   Vertex* vertexA = graph1.AddVertex("Tokyo");
   Vertex* vertexB = graph1.AddVertex("New York");
   Vertex* vertexC = graph1.AddVertex("London");
   Vertex* vertexD = graph1.AddVertex("Sydney");
   graph1.AddUndirectedEdge(vertexA, vertexB, 6743);
   graph1.AddUndirectedEdge(vertexA, vertexC, 5941);
   graph1.AddUndirectedEdge(vertexA, vertexD, 4863);
   graph1.AddUndirectedEdge(vertexB, vertexC, 3425);
   graph1.AddUndirectedEdge(vertexB, vertexD, 9868);
   graph1.AddUndirectedEdge(vertexC, vertexD, 10562);
    
   // Show the graph's vertices and edges
   for (Vertex* vertex : graph1.GetVertices()) {
      cout << "Location: " << vertex->label << endl;
        
      // Show outgoing edges (flights from location)
      cout << "  Flights from " << vertex->label << ":" << endl;
      for (Edge* outgoingEdge : *graph1.GetEdgesFrom(vertex)) {
         cout << "   - " << vertex->label << " to ";
         cout << outgoingEdge->toVertex->label << ", ";
         cout << (int)outgoingEdge->weight << " miles" << endl;
      }
     
      // Show incoming edges (flights to location)
      cout << "  Flights to " << vertex->label << ":" << endl;
      for (Edge* incomingEdge : *graph1.GetEdgesTo(vertex)) {
         cout << "   - " << incomingEdge->fromVertex->label << " to ";
         cout << vertex->label << ", ";
         cout << (int)incomingEdge->weight << " miles" << endl;
      }
   }
    
   return 0;
}