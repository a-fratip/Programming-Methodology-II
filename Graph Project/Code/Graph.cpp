#include "Graph.h"


    
Graph::Graph(const Graph& rhs)
    : vertices{rhs.vertices}
    {
        
    }
    

bool Graph::searchVertex(const Vertex& v) const {
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i) == v)
            return true;
    }
    return false;
}

int Graph::getVindexByID(int vid) const {
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i) == vid)
            return i;
    }
    return -1;
}

bool Graph::addVertex(Vertex& v) {
    // check if the vertex already exists in the graph
    bool check = searchVertex(v);
    if (check == true) {
        cout << "Vertex with this ID already exists!" << endl;
        return false;
    }
    // if vertex is not already in graph
    // add vertex to list of vertices
    vertices.push_back(v);
    cout << "New vertex added successfully" << endl;
    return true;
}

bool Graph::searchEdge(Vertex& start,Vertex& end) const {
    // get end vertex id
    int endVertexID = end.getID();
    // get edge list of start vertex
    vector <Edge> e = start.getEdgeList();
    // iterate through starting vertex edge list and search for an edge with end vertex id
    for (auto it = e.begin(); it != e.end(); it++) {
        if (it->getEndID() == endVertexID) {
            cout << "Edge exists in the graph!" << endl;
            return true;
        }
    }
    cout << "Edge does not exist in the graph" << endl;
    return false;
}

bool Graph::searchVertexValue(int val) const {
    bool flag = false;
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).getValue() == val) {
            cout << "Vertex with ID " << vertices.at(i).getID() << " contains the value " << val << endl;
            flag = true; // vertex value was found
        }
    }
    if (!flag) // vertex value was not found
        cout << "There are no vertices on the graph with the value " << val << endl;
    
    return flag;
}

Vertex Graph::getVertexByName(string name) {
    Vertex temp;
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).getName() == name) {
            temp = vertices.at(i);
            return temp;
        }
    }
    return temp;
}

void Graph::printGraph() const {
    for (int i = 0; i < vertices.size(); i++) {
        cout << vertices.at(i).getName() << " (" << vertices.at(i).getID() << ") --> ";
        vertices.at(i).printEdgeList();
    }
}

void Graph::printNeighbourhoodByID(int vid) {
    cout << vid << " --> ";
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).getID() == vid) {
            for (auto it = vertices.at(i).getEdgeList().begin(); it != vertices.at(i).getEdgeList().end(); it++)
                cout << it->getEndID() << " --> ";
        }
    }
    cout << endl;
}
