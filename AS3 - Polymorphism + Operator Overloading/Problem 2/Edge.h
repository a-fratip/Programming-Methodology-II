#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"

class Edge {
private:
    int weight; // an edge has a weight
    Vertex *start; // pointer to an edge's starting vertex
    Vertex *end; // pointer to an edge's ending vertex
public:
    Edge(); // default constructor
    Edge(int, Vertex*, Vertex*); // parametrized constructor
    Edge(const Edge&); // copy constructor 
    ~Edge(); // destructor
    
    // getters
    int getWeight() const;
    int getStartID() const;
    int getStartValue() const;
    int getEndID() const;
    int getEndValue() const;
    Vertex* getStart() const;
    Vertex* getEnd() const;
    
    // setters
    void setWeight(int);
    void setStartVertex(int);
    void setEndVertex(int);
    
    
    
};

#endif