#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Vertex {
public:
   std::string label;
   
   static inline int s_instCount = 0;
   
   Vertex(const std::string& vertexLabel) {
      label = vertexLabel;
   }
};

class Edge {
public:
   Vertex* fromVertex;
   Vertex* toVertex;
   double weight;
    
   Edge(Vertex* from, Vertex* to, double edgeWeight) {
      fromVertex = from;
      toVertex = to;
      weight = edgeWeight;
   }
};

class Graph {
private:
   // Maps a vertex to a List of all edges that start from that vertex
   std::unordered_map<Vertex*, std::vector<Edge*>*> fromEdges;
    
   // Maps a vertex to an ArrayList of all edges that go to that vertex
   std::unordered_map<Vertex*, std::vector<Edge*>*> toEdges;

public:    
   virtual ~Graph() {
      // Get the set of vertices and the set of edges
      std::unordered_set<Vertex*> distinctVertices;
      std::unordered_set<Edge*> distinctEdges;
      for (auto& keyValue : fromEdges) {
         distinctVertices.insert(keyValue.first);
         for (Edge* edge : *keyValue.second) {
            distinctEdges.insert(edge);
         }
      }
      for (auto& keyValue : toEdges) {
         distinctVertices.insert(keyValue.first);
         for (Edge* edge : *keyValue.second) {
            distinctEdges.insert(edge);
         }
      }
        
      // Clear each map
      fromEdges.clear();
      toEdges.clear();
        
      // Free each edge and each vertex
      for (Edge* edge : distinctEdges) {
         delete edge;
      }
      for (Vertex* vertex : distinctVertices) {
         delete vertex;
      }
   }
    
   Vertex* AddVertex(const std::string& newVertexLabel) {
      // Create the new Vertex object
      Vertex* newVertex = new Vertex(newVertexLabel);
        
      // Every vertex must exist as a key in both maps
      fromEdges[newVertex] = new std::vector<Edge*>();
      toEdges[newVertex] = new std::vector<Edge*>();
        
      return newVertex;
   }
    
   Edge* AddDirectedEdge(Vertex* fromVertex, Vertex* toVertex, double weight = 1.0) {
      // Don't add the same edge twice
      if (HasEdge(fromVertex, toVertex)) {
         return nullptr;
      }
        
      // Create the Edge object
      Edge* newEdge = new Edge(fromVertex, toVertex, weight);
        
      // Add the edge to the appropriate list in both maps
      fromEdges[fromVertex]->push_back(newEdge);
      toEdges[toVertex]->push_back(newEdge);
        
      return newEdge;
   }
    
   std::pair<Edge*, Edge*> AddUndirectedEdge(Vertex* vertexA, Vertex* vertexB, 
      double weight = 1.0) {
         return std::pair<Edge*, Edge*>(
            AddDirectedEdge(vertexA, vertexB, weight),
            AddDirectedEdge(vertexB, vertexA, weight));
   }
    
   // Returns an unordered_set of all of this graph's edges
   std::unordered_set<Edge*> GetEdges() const {
      std::unordered_set<Edge*> edgesSet;
      for (auto& keyValue : fromEdges) {
         std::vector<Edge*>* edges = keyValue.second;
         for (Edge* edge : *edges) {
            edgesSet.insert(edge);
         }
      }
      return edgesSet;
   }
    
   // Returns a vector of edges with the specified fromVertex
   const std::vector<Edge*>* GetEdgesFrom(Vertex* fromVertex) const {
      return fromEdges.at(fromVertex);
   }
    
   // Returns a vector of edges with the specified toVertex
   const std::vector<Edge*>* GetEdgesTo(Vertex* toVertex) const {
      return toEdges.at(toVertex);
   }
    
   // Returns a vertex with a matching label, or nullptr if no such vertex exists
   Vertex* GetVertex(const std::string& vertexLabel) {
      for (auto& keyValue : fromEdges) {
         Vertex* vertex = keyValue.first;
         if (vertex->label == vertexLabel) {
            return keyValue.first;
         }
      }
      return nullptr;
   }
    
   // Returns a vector of all of this graph's vertices
   std::vector<Vertex*> GetVertices() const {
      std::vector<Vertex*> vertices;
      for (auto& keyValue : fromEdges) {
         vertices.push_back(keyValue.first);
      }
      return vertices;
   }
    
   // Returns true if this graph has an edge from fromVertex to toVertex
   bool HasEdge(Vertex* fromVertex, Vertex* toVertex) const {
      if (0 == fromEdges.count(fromVertex)) {
         // fromVertex is not in this graph
         return false;
      }
        
      // Search the list of edges for an edge that goes to toVertex
      std::vector<Edge*>& edges = *fromEdges.at(fromVertex);
      for (Edge* edge : edges) {
         if (edge->toVertex == toVertex) {
            return true;
         }
      }
        
      return false;
   }
};

#endif