#include "Directed.h"

#include <vector>

#include <iostream>
using namespace std;

Directed::Directed()
    : Graph(), EdgeWeightTotal{0}
    {
        
    }
    
Directed::Directed(const Directed& rhs)
    : Graph(rhs) , EdgeWeightTotal{rhs.EdgeWeightTotal}
    {
        
    }
    
int Directed::getEdgeWeights() const { return EdgeWeightTotal; }
    
bool Directed::removeVertex(Vertex& v) {
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


bool Directed::addEdge(Vertex* start,Vertex* end,int weight) {
    // check if vertices are in the graph
    bool check1 = searchVertex(*start);
    bool check2 = searchVertex(*end);
    // check if edge already exists in the graph
    bool check3 = searchEdge(*start,*end);
    
    if (check1 == true && check2 == true) { // vertices are in the graph
        if (check3 == true) { // edge also exists
            cout << "Edge between " << start->getName() << "(" << start->getID() << ") and "
                 << end->getName() << "(" << end->getID() << ") already exist" << endl;
            return false;
        }
        else { // edge does not exist
            for (int i = 0; i < vertices.size(); i++) {
                // add directed edge
                if (vertices.at(i).getName() == start->getName()) {
                    vertices.at(i).addEdgetoEdgeList(end,weight);
                }
            }
            EdgeWeightTotal += weight; // add to total edge weight of graph
            cout << "Edge addition complete" << endl;
            return true;
        }
    }
    else { // one or both vertices are not in the graph
        cout << "Invalid vertices entered" << endl;
        return false;
    }
} 

bool Directed::removeEdge(Vertex& start,Vertex& end) {
    // check if edge exists
    bool check = searchEdge(start,end);
    if (check == true) { // edge exists
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices.at(i).getID() == start.getID()) { // find start vertex in vertices array
                // iterate through its edge list
                for (auto it = vertices.at(i).getEdgeList().begin(); it != vertices.at(i).getEdgeList().end(); it++) {
                    if (it->getEndID() == end.getID()) { // find edge ending with end vertex
                        EdgeWeightTotal -= it->getWeight(); // subtract its weight from total edge weight of graph
                        vertices.at(i).getEdgeList().erase(it); // remove the edge
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

size_t Directed::getNumEdges() const {
    size_t v_degrees = 0;
    for (size_t i = 0; i < vertices.size(); i++) {
        // get the sum of all vertex degrees 
        v_degrees += vertices.at(i).getDegree();
    }
    
    return v_degrees; // number of edges in directed graph is the the sum of vertex degrees
}

// operator overloading

// returns true if G1 and G2 have the exact same vertices and edges
bool Directed::operator==(Directed& rhs) const {
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
const Directed& Directed::operator=(const Directed& rhs) {
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
Directed& Directed::operator++() { // pre increment
    for (int i = 0; i < vertices.size(); i++) {
        for (auto it = vertices.at(i).getEdgeList().begin(); it != vertices.at(i).getEdgeList().end(); it++) {
            it->setWeight(it->getWeight() + 1);
        }
    }
    
    EdgeWeightTotal += this->getNumEdges();
    
    return *this;
}

Directed Directed::operator++(int) { // post increment 
    Directed temp(*this); // make a copy of current object
    ++(*this); // call pre-increment for current object
    return temp; // return unmodified copy object
}

//G1>G2 if its sum of edge weights is greater than the sum of G2's edge weights
bool Directed::operator>(const Directed& rhs) const {
    return (this->getEdgeWeights() > rhs.getEdgeWeights());
}

// returns a graph that contains the nodes of vertices of both G1 and G2
Directed& Directed::operator+(const Directed& rhs) {
    vertices.insert(vertices.end(),rhs.vertices.begin(),rhs.vertices.end());        
    EdgeWeightTotal += rhs.EdgeWeightTotal;
        
    return *this;
}

// output graph information
std::ostream& operator<<(std::ostream& os, const Directed& rhs) {
    os << "Graph type: Directed" << endl
        << "Number of vertices: " << rhs.vertices.size() << endl
        << "Number of edges: " << rhs.getNumEdges() << endl
        << "Sum of all edge weights: " << rhs.EdgeWeightTotal << endl;
    rhs.printGraph();
    
    return os;
}











