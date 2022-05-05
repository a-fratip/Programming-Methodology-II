#ifndef DIRECTED_H
#define DIRECTED_H

#include "Graph.h"

class Directed : public Graph {
    // overloaded stream insertion
    friend std::ostream& operator<<(std::ostream&, const Directed&);
    
public:
    Directed();
    Directed(const Directed&);
    virtual ~Directed() = default;
    
    virtual bool addVertex(Vertex &v);
    virtual bool addVertices(Vertex* vArray, int size);
    virtual bool removeVertex(Vertex &v);
    
    virtual bool addEdge(Edge &e);
    virtual bool removeEdge(Edge &e);
    
    virtual bool searchVertex(const Vertex& v) const;
    virtual bool searchEdge(const Edge &e) const;
    
    virtual void listVertices() const;
    
    virtual void display() const;
    
    virtual std::string toString() const;
    
    virtual bool clean();
    
    // operators
    
    bool operator==(const Directed&) const; // equality operator
    const Directed& operator=(const Directed&); // assignemnt operator
    Directed& operator++(); // pre-increment
    Directed operator++(int); // post-increment
    bool operator>(const Directed&) const; // greater-than relational operator
    Directed& operator+(const Directed&); // "plus" operator
    
    
};

#endif