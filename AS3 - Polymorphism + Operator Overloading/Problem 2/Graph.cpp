#include "Graph.h"

Graph::Graph()
    : numVertices{0}, numEdges{0}
    {
        vertices = new Vertex[maxVertices];
        edges = new Edge[maxEdges];
    }
    
Graph::Graph(const Graph& rhs)
    : numVertices{rhs.numVertices} , numEdges{rhs.numEdges}
    {
        vertices = new Vertex[maxVertices];
        edges = new Edge[maxEdges];
        for (int i = 0; i < numVertices; i++)
            vertices[i] = rhs.vertices[i];
        for (int j = 0; j < numEdges; j++)
            edges[j] = rhs.edges[j];
    }
    
Graph::~Graph() {
    delete [] vertices;
    delete [] edges;
}

int Graph::get_numVertices() const { return numVertices; }

int Graph::get_numEdges() const { return numEdges; }

int Graph::edgeWeightTotal() const {
    int sum = 0;
    for (int i = 0; i < numEdges; i++)
        sum += edges[i].getWeight();
    
    return sum; 
}
