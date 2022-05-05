#ifndef VERTEX_H
#define VERTEX_H

#include "Edge.h"

#include <string>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

class Edge;

class Vertex {
private:
    static int id_counter; // creates unique vertex IDs
    int id; // store's a vertex's unique state id
    int value; // a vertex's value
    string name; // state name
    vector <Edge> edgeList; // end vertex of an edge, start is 'this' vertex
public:
    Vertex(int = 0, string = ""); // constructor with vertex value and name -- default values set to 0 and empty string
    
    // getters
    int getID() const;
    int getValue() const;
    string getName() const;
    vector <Edge>& getEdgeList();
    size_t getDegree() const; // returns the degree of a vertex
    
    // setters
    void setValue(int);
    void setName(string);
    
    // edge list functions
    void addEdgetoEdgeList(Vertex*,int); // add an edge from 'this' vertex by specifying end vertex and weight of edge
    void printEdgeList() const;
    
    // overloaded equality operators
    bool operator==(const Vertex&) const; 
    bool operator!=(const Vertex&) const;
    
};

#endif