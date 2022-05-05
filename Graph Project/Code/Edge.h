#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"

#include <string>
using namespace std;

class Vertex;

class Edge {
private:
    int weight; // an edge has a weight
    Vertex *end; // pointer to an edge's ending vertex
public:
    Edge(); // default constructor
    Edge(int, Vertex*); // parametrized constructor
    Edge(const Edge&); // copy constructor 
    ~Edge(); // destructor
    
    // getters
    int getWeight() const;
    int getEndID() const;
    int getEndValue() const;
    Vertex* getEnd() const;
    
    // setters
    void setWeight(int);
    void setEndVertex(int,string);
    
};

#endif