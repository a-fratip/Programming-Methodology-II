#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"
#include "Vertex.h"

#include <string>

class Graph {
protected:
    vector <Vertex> vertices; // a graph can be represented as a list of vertices which includes their edge lists
public:
    Graph() = default; // default constructor 
    Graph(const Graph&); // copy constructor
    virtual ~Graph() = default; // destructor
    
    // add in one vertex; bool returns if it as added successfully
    bool addVertex(Vertex &v);
    
    // remove one vertex; the edges that have a connection with this vertex are also removed
    virtual bool removeVertex(Vertex &v) = 0;
    
    // add in one edge
    virtual bool addEdge(Vertex*,Vertex*,int) = 0;
    
    // remove an edge; as a result, some node may remain as orphan
    virtual bool removeEdge(Vertex&,Vertex&) = 0;
    
    // return bool if a vertex exists in a graph
    bool searchVertex(const Vertex& v) const;
    
    // return bool if an edge exists between two vertices in a graph
    bool searchEdge(Vertex&,Vertex&) const;
    
    // return bool if a value is contained by any of its vertex
    bool searchVertexValue(int val) const;
    
    // display the whole graph by listing all possible paths (list of edges)
    void printGraph() const;
    
    // return the vertex in the graph with a specified name
    Vertex getVertexByName(string);
    
    // print the path from a starting vertex by specifiying a vertex id and printing its neighbouring vertices
    void printNeighbourhoodByID(int);
    
    // returns the number of edges in a graph
    virtual size_t getNumEdges() const = 0;
    
    int getVindexByID(int) const;
    
};

#endif