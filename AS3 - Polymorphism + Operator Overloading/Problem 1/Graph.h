#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"

#include <string>

class Graph {
protected:
    int numVertices; // current size of vertices array
    int numEdges; // current size of edges array
    Vertex* vertices; // pointer to an array of vertex objects
    Edge* edges; // pointer to an array of edge objects
    static constexpr int maxVertices = 50; // max size for vertices 
    static constexpr int maxEdges = 100; // max size for edges
public:
    Graph(); // default constructor 
    Graph(const Graph&); // copy constructor
    virtual ~Graph(); // destructor
    
    // getters
    int get_numVertices() const;
    int get_numEdges() const;
    
    // add in one vertex; bool returns if it as added successfully
    virtual bool addVertex(Vertex &v) = 0;
    
    // add a vertex array ; pass the size of the array
    virtual bool addVertices(Vertex* vArray, int size) = 0;
    
    // remove one vertex; the edges that have a connection with this vertex are also removed
    virtual bool removeVertex(Vertex &v) = 0;
    
    // add in one edge
    virtual bool addEdge(Edge &e) = 0;
    
    // remove an edge; as a result, some node may remain as orphan
    virtual bool removeEdge(Edge &e) = 0;
    
    // return bool if a vertex exists in a graph
    virtual bool searchVertex(const Vertex& v) = 0;
    
    // return bool if an edge exists in a graph
    virtual bool searchEdge(const Edge &e) = 0;
    
    // display the whole graph by listing all of its edges
    virtual void display() const = 0;
    
    // a string representation of the graph
    // convert the graph to a string of vertex IDs such as 1-2-3-4-5
    // every edge has a pair of nodes; the resulting IDs from every edge are listed in the order in which the edges are added
    virtual std::string toString() const = 0;
    
    // remove all vertices and edges
    virtual bool clean() = 0;
    
};

#endif