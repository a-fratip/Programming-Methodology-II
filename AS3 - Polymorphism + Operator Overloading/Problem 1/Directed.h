#ifndef DIRECTED_H
#define DIRECTED_H

#include "Graph.h"

class Directed : public Graph {
public:
    Directed();
    Directed(const Directed&);
    virtual ~Directed() = default;
    
    virtual bool addVertex(Vertex &v);
    virtual bool addVertices(Vertex* vArray, int size);
    virtual bool removeVertex(Vertex &v);
    
    virtual bool addEdge(Edge &e);
    virtual bool removeEdge(Edge &e);
    
    virtual bool searchVertex(const Vertex& v);
    virtual bool searchEdge(const Edge &e);
    
    virtual void display() const;
    
    virtual std::string toString() const;
    
    virtual bool clean();
    
    
};

#endif