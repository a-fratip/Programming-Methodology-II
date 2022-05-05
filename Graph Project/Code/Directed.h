#ifndef DIRECTED_H
#define DIRECTED_H

#include "Graph.h"

class Directed : public Graph {
    // overloaded stream insertion
    friend std::ostream& operator<<(std::ostream&, const Directed&);
    
private:
    int EdgeWeightTotal; // sum of all edge weights
    
public:
    Directed();
    Directed(const Directed&);
    virtual ~Directed() = default;
    
    // vertex functions
    virtual bool removeVertex(Vertex &v);
    
    // edge functions
    virtual bool addEdge(Vertex*,Vertex*,int);
    virtual bool removeEdge(Vertex&,Vertex&);
    
    int getEdgeWeights() const;
    virtual size_t getNumEdges() const;
    
    // operators
    bool operator==(Directed&) const; // equality operator
    const Directed& operator=(const Directed&); // assignment operator
    Directed& operator++(); // pre-increment
    Directed operator++(int); // post-increment
    bool operator>(const Directed&) const; // greater-than relational operator
    Directed& operator+(const Directed&); // "plus" operator
    
};

#endif