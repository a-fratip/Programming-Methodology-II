#ifndef UNDIRECTED_H
#define UNDIRECTED_H

#include "Graph.h"

class Undirected : public Graph {
     // overloaded stream insertion
    friend std::ostream& operator<<(std::ostream&, const Undirected&);
    
private:
    int EdgeWeightTotal; // sum of all edge weights
public:
    Undirected();
    Undirected(const Undirected&);
    virtual ~Undirected() = default;
    
    // edge functions
    virtual bool addEdge(Vertex*,Vertex*,int);
    virtual bool removeEdge(Vertex&,Vertex&);
    
    int getEdgeWeights() const;
    virtual size_t getNumEdges() const;
    
    // vertex functions
    virtual bool removeVertex(Vertex&);
    
     // operators
    bool operator==(Undirected&) const; // equality operator
    const Undirected& operator=(const Undirected&); // assignment operator
    Undirected& operator++(); // pre-increment
    Undirected operator++(int); // post-increment
    bool operator>(const Undirected&) const; // greater-than relational operator
    Undirected& operator+(const Undirected&); // "plus" operator
    
};

#endif