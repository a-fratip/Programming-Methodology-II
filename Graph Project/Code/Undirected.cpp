#include "Undirected.h"

#include <vector>

#include <iostream>
using namespace std;

Undirected::Undirected()
    : Graph(), EdgeWeightTotal{0}
    {
        
    }
    
Undirected::Undirected(const Undirected& rhs)
    : Graph(rhs), EdgeWeightTotal{rhs.EdgeWeightTotal}
    {
        
    }
    
int Undirected::getEdgeWeights() const { return EdgeWeightTotal; }
    
bool Undirected::addEdge(Vertex* start, Vertex* end, int weight) {
    // check if vertices are in the graph
    bool check1 = searchVertex(*start);
    bool check2 = searchVertex(*end);
    // check if edge already exists in the graph
    bool check3 = searchEdge(*start,*end);
    
    if (check1 == true && check2 == true) { // vertices are in the graph
        if (check3 == true) { // edge also exist
            cout << "Edge between " << start->getName() << "(" << start->getID() << ") and "
                 << end->getName() << "(" << end->getID() << ") already exist" << endl;
            return false;
        }
        else { // vertices are in the graph, but edge does not exist
            for (int i = 0; i < vertices.size(); i++) {
                // add undirected edge
                if (vertices.at(i).getID() == start->getID()) {
                    vertices.at(i).addEdgetoEdgeList(end,weight);
                }
                else if (vertices.at(i).getID() == end->getID()) {
                    vertices.at(i).addEdgetoEdgeList(start,weight);
                }
            }
            EdgeWeightTotal += weight; // add to graph's total edge weight
            cout << "Edge addition complete" << endl;
            return true;
        }
    }
    else { // one or both vertices are not in the graph
        cout << "Invalid vertices entered" << endl;
        return false;
    }
}

bool Undirected::removeEdge(Vertex& start,Vertex& end) {
    // check if edge exists
    bool check = searchEdge(start,end);
    if (check == true) { // edge exists
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices.at(i).getID() == start.getID()) { // find start vertex
                // iterate through its edge list
                for (auto it = vertices.at(i).getEdgeList().begin(); it != vertices.at(i).getEdgeList().end(); it++) {
                    if (it->getEndID() == end.getID()) { // check for edge with ending with end vertex
                        EdgeWeightTotal -= it->getWeight(); // subtract edge weight from total
                        vertices.at(i).getEdgeList().erase(it); // first erase
                        break;
                    }
                }
            }
            if (vertices.at(i).getID() == end.getID()) { // find end vertex
                // iterate through its edge list
                for (auto it = vertices.at(i).getEdgeList().begin(); it != vertices.at(i).getEdgeList().end(); it++) {
                    if (it->getEndID() == start.getID()) { //  check for edge ending with start vertex
                        EdgeWeightTotal -= it->getWeight(); // subtract edge weight from total
                        vertices.at(i).getEdgeList().erase(it); // second erase
                        break;
                    }
                }
            }
        }
        cout << "Edge between " << start.getID() << " and " << end.getID() << " successfully removed" << endl;
        return true;
    }
    return false;
}

bool Undirected::removeVertex(Vertex& v) {
    int vIndex = 0;
    bool found = false;
    // get position of vertex to be removed
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).getID() == v.getID()) {
            vIndex = i;
            found = true;
        }
    }
    if (!found) { // vertex to be removed is not in graph
        cout << "Vertex could not be found!" << endl;
        return false;
    }
    
    // remove all edges pointing to removal vertex
    for (int i = 0; i < vertices.size(); i++) {
        for (auto it = vertices.at(i).getEdgeList().begin(); it != vertices.at(i).getEdgeList().end(); it++) {
            if (it -> getEndID() == v.getID()) {
                vertices.at(i).getEdgeList().erase(it);
                break;
            }
        }
    }
 
    // remove the vertex
    vertices.erase(vertices.begin() + vIndex);
    cout << "Vertex removed successfully" << endl;
    return true;
}

size_t Undirected::getNumEdges() const {
    size_t v_degrees = 0;
    for (size_t i = 0; i < vertices.size(); i++) {
        // get the sum of all vertex degrees
        v_degrees += vertices.at(i).getDegree();
    }
    
    return v_degrees/2; // number of edges in undirected graph is the sum of all vertex degrees divided by 2
}

// operator overloading

// returns true if G1 and G2 have the exact same vertices and edges
bool Undirected::operator==(Undirected& rhs) const {
    // check if number of vertices are the same
    if (vertices.size() != rhs.vertices.size())
        return false;
    // check if number of edges are the same
    if (this->getNumEdges() != rhs.getNumEdges())
        return false;
    // if graphs have the same number of vertices and edges, check if they have the same vertices    
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i) != rhs.vertices.at(i))
            return false;
    }
    // if graphs have the same number of vertices and edges, and the same vertices, check if they have the same edges        
    for (int i = 0; i < rhs.vertices.size(); i++) {
        for (auto it = rhs.vertices.at(i).getEdgeList().begin(); it != rhs.vertices.at(i).getEdgeList().end(); it++)
            if (!(this->searchEdge(rhs.vertices.at(i),*(it->getEnd()))))
                return false;
    }
            
    return true;
}

// assigns G2 to G1
const Undirected& Undirected::operator=(const Undirected& rhs) {
    if (&rhs != this) { // check for self-assignment
        vertices.clear();
        EdgeWeightTotal = rhs.EdgeWeightTotal;
        
        for (int i = 0; i < rhs.vertices.size(); i++) {
            vertices.push_back(rhs.vertices.at(i));
        }
    }
    return *this;
}

//increase the weight of all edges by 1
Undirected& Undirected::operator++() { // pre increment
    for (int i = 0; i < vertices.size(); i++) {
        for (auto it = vertices.at(i).getEdgeList().begin(); it != vertices.at(i).getEdgeList().end(); it++) {
            it->setWeight(it->getWeight() + 1);
        }
    }
    
    EdgeWeightTotal += this->getNumEdges();
    
    return *this;
}

Undirected Undirected::operator++(int) { // post increment 
    Undirected temp(*this); // make a copy of current object
    ++(*this); // call pre-increment for current object
    return temp; // return unmodified copy object
}

//G1>G2 if its sum of edge weights is greater than the sum of G2's edge weights
bool Undirected::operator>(const Undirected& rhs) const {
    return (this->getEdgeWeights() > rhs.getEdgeWeights());
}

// returns a graph that contains the nodes of vertices of both G1 and G2
Undirected& Undirected::operator+(const Undirected& rhs) {
    vertices.insert(vertices.end(),rhs.vertices.begin(),rhs.vertices.end());        
    EdgeWeightTotal += rhs.EdgeWeightTotal;
        
    return *this;
}

// output graph information
std::ostream& operator<<(std::ostream& os, const Undirected& rhs) {
    os << "Graph type: Undirected" << endl
        << "Number of vertices: " << rhs.vertices.size() << endl
        << "Number of edges: " << rhs.getNumEdges() << endl
        << "Sum of all edge weights: " << rhs.EdgeWeightTotal << endl;
    rhs.printGraph();
    
    return os;
}
