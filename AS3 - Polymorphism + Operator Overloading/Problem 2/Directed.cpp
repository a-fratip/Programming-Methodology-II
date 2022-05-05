#include "Directed.h"

#include <vector>

#include <iostream>
using namespace std;

Directed::Directed()
    : Graph()
    {
        
    }
    
Directed::Directed(const Directed& rhs)
    : Graph(rhs)
    {
        
    }
    
bool Directed::searchVertex(const Vertex& v) const {
    for (int i = 0; i < numVertices; i++) {
        if (vertices[i].getID() == v.getID())
            return true;
    }
    return false;
}

bool Directed::addVertex(Vertex& v) {
    if ( numVertices < maxVertices) { // check if capacity has been reached
        if (!searchVertex(v)) { // check if vertex already exists
            vertices[numVertices] = v;
            numVertices++;
            cout << "Vertex with ID = " << v.getID() << " successfully added" << endl;
            return true;
        }
        cout << "Vertex with ID = " << v.getID() << " already exists in the graph" << endl;
        return false;
    }
    cout << "Maximum number of vertices for this graph has been reached" << endl;
    return false;
}

bool Directed::addVertices(Vertex* vArray, int size) {
    for (int i = 0; i < size; i++) {
        if (!addVertex(vArray[i]))
            return false;
    }
    return true;
}

bool Directed::removeVertex(Vertex& v) {
    if (searchVertex(v)) { // check if the vertex is in the graph
    // removes vertex from vertices array by shifting the elements 
        for (int i = 0; i < numVertices; i++) {
            if (vertices[i].getID() == v.getID()) {
                for (int j = i; j < numVertices - 1; j++)
                    vertices[j] = vertices[j+1];
                numVertices--;
            } // end if
        } // end for
    // now need to filter through edges array to remove edges connected to vertex v
    int k = 0; // set looping variable
    while (k < numEdges) {
        if (edges[k].getStartID() == v.getID() || edges[k].getEndID() == v.getID()) {
            if (!removeEdge(edges[k])) {
                cout << "Vertex with ID = " << v.getID() << " not successfully removed" << endl;
                return false;
            }
            k = -1; // if edge removal was successful, need to reset looping variable since edges array has been shifted
            // when k is incremented, it will be reset to 0 so looping will start at the begining of newly shifted array
        }
        k++;
    }
    cout << "Vertex with ID = " << v.getID() << " successfully removed" << endl;
    return true;
    }
    cout << "Vertex with ID = " << v.getID() << " could not be found" << endl;
    return false;
}

bool Directed::addEdge(Edge& e) {
    if (!searchVertex(*e.getStart()) || !searchVertex(*e.getEnd())) { // check if the edge's vertices are on the graph
        cout << "At least one of the edge's vertices are not on the graph" << endl;
        return false;
    }
    if (numEdges < maxEdges) { // check if edge capacity has been reached
        if (!searchEdge(e)) { // check if edge already exists
            edges[numEdges] = e;
            numEdges++;
            cout << "Edge successfully added" << endl;
            return true;
        }
        cout << "Edge already exists in the graph" << endl;
        return false;
    }
    cout << "Maximum number of edges on this graph has been reached" << endl;
    return false;
}

bool Directed::removeEdge(Edge& e) {
    if (searchEdge(e)) { // check if edge is in the edges array 
    // remove edge from edges array by shifting elements
        for (int i = 0; i < numEdges; i++) {
            if (edges[i].getStartID() == e.getStartID() && edges[i].getEndID() == e.getEndID()) {
                for (int j = i; j < numEdges - 1; j++)
                    edges[j] = edges[j+1];
                numEdges--;
                cout << "Edge successfully removed" << endl;
                return true;
        }
    }
    }
    cout << "Edge could not be found" << endl;
    return false;
}

bool Directed::searchEdge(const Edge& e) const {
    for (int i = 0; i < numEdges; i++) {
        if (edges[i].getStartID() == e.getStartID() && edges[i].getEndID() == e.getEndID())
            return true;
    }
    return false;
}

void Directed::listVertices() const {
    cout << "---------------List of vertices---------------" << endl;
    cout << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex with ID " << vertices[i].getID() << " has value " << vertices[i].getValue() << endl;
        cout << endl;
    }
    
}

void Directed::display() const {
    cout << "---------------List of edges---------------" << endl;
    cout << endl;
    for (int i = 0; i < numEdges; i++) {
        cout << "Edge " << i + 1 << "::" << endl;
        cout << "Starting at vertex with ID " << edges[i].getStartID() << endl;
        cout << "Ending at vertex with ID " << edges[i].getEndID() << endl;
        cout << "Weight: " << edges[i].getWeight() << endl;
        cout << endl;
    }
}

string Directed::toString() const {
    vector<int> id_vals; // placeholder for collection of vertex IDs
   
    // iterate through edges array and add each edge's pair of vertex ID's to vector
    for (int i = 0; i < numEdges; i++) {
        id_vals.push_back(edges[i].getStartID());
        id_vals.push_back(edges[i].getEndID());
    }
    
    string s; // string object to represent graph 
    
    // iterate over the vector's (size -2) elements and add them to the string seperated by a '-' 
    for (size_t i = 0; i < id_vals.size() - 1; i++) {
        s += to_string(id_vals.at(i)); // use to_string function to convert int to string
        s += "-";
    }
    s += to_string(id_vals.at(id_vals.size()-1)); // add the vectors last element to the string 
    
    return s;
}

bool Directed::clean() {
    numVertices = 0;
    numEdges = 0;
    
    cout << "Graph cleaning successful" << endl;
    return true;
}

// operator overloading

// returns true if G1 and G2 have the exact same vertices and edges
bool Directed::operator==(const Directed& rhs) const {
    // check if number of vertices are the same
    if (numVertices != rhs.get_numVertices())
        return false;
    // check if number of edges are the same
    if (numEdges != rhs.get_numEdges())
        return false;
    // if graphs have the same number of vertices and edges, check if they have the same vertices    
    for (int i = 0; i < numVertices; i++) {
        if (vertices[i] != rhs.vertices[i])
            return false;
    }
    // if graphs have the same number of vertices and edges, and the same vertices, check if they have the same edges        
    for (int i = 0; i < numEdges; i++) {
        if (!(this->searchEdge(rhs.edges[i])))
            return false;
    }
            
    return true;
}

// assigns G2 to G1
const Directed& Directed::operator=(const Directed& rhs) {
    if (&rhs != this) { // check for self-assignment
        if (numVertices != rhs.get_numVertices()) // check if number of vertices are equal
            numVertices = rhs.get_numVertices();
        
        if (numEdges != rhs.get_numEdges()) // check if number of edges are equal
            numEdges = rhs.get_numEdges();
            
        for (int i = 0; i < numVertices; i++) 
            vertices[i] = rhs.vertices[i];
        
        for (int j = 0; j < numEdges; j++)
            edges[j] = rhs.edges[j];
    }
    return *this;
}

//increase the weight of all edges by 1
Directed& Directed::operator++() { // pre increment
    for (int i = 0; i < numEdges; i++)
        edges[i].setWeight(edges[i].getWeight() + 1);
    return *this;
}

Directed Directed::operator++(int) { // post increment 
    Directed temp(*this); // make a copy of current object
    ++(*this); // call pre-increment for current object
    return temp; // return unmodified copy object
}

//G1>G2 if its sum of edge weights is greater than the sum of G2's edge weights
bool Directed::operator>(const Directed& rhs) const {
    return (this->edgeWeightTotal() > rhs.edgeWeightTotal());
}

// returns a graph that contains the nodes of vertices of both G1 and G2
Directed& Directed::operator+(const Directed& rhs) {
    for (int i = 0; i < rhs.get_numVertices(); i++) // iterate through vertices of G2
        this->addVertex(rhs.vertices[i]); // add vertices of G2 to G1
    for (int i = 0; i < rhs.get_numEdges(); i++) // iterate through edges of G2
        this->addEdge(rhs.edges[i]); // add edges of G2 to G1
        
    return *this;
}

// output graph information
std::ostream& operator<<(std::ostream& os, const Directed& rhs) {
    os << "Graph type: Directed" << endl
        << "Number of vertices: " << rhs.numVertices << endl
        << "Number of edges: " << rhs.numEdges << endl;
    rhs.listVertices();
    rhs.display();
    
    return os;
}


