#include "Directed.h"

#include <iostream>
using namespace std;

int main() { // driver to test overloaded operators
    
    // Test creation of a directed graph
    // Example given below; G = (N,E)
    // V = {1,2,3,4,5,6}
    // E = {(1,2),(1,4),(2,3),(2,4),(2,5),(3,4),(5,3),(6,3),(6,5)}
    
    // creates vertices
    Vertex* v1 = new Vertex(); // deafult constructor will initialize value to 0
    // initialize vertices with values
    Vertex* v2 = new Vertex(1);
    Vertex* v3 = new Vertex(2);
    Vertex* v4 = new Vertex(3);
    Vertex* v5 = new Vertex(4);
    Vertex* v6 = new Vertex(7);
    Vertex* v7 = new Vertex(8);
    Vertex* v8 = new Vertex(21);
    Vertex* v9 = new Vertex(10);
    
    // create edges
    // initialize edges with weight, starting, and ending vertex
    Edge* e1 = new Edge(1,v1,v2);
    Edge* e2 = new Edge(2,v1,v4);
    Edge* e3 = new Edge(3,v2,v3);
    Edge* e4 = new Edge(4,v2,v4);
    Edge* e5 = new Edge(5,v2,v5);
    Edge* e6 = new Edge(6,v3,v4);
    Edge* e7 = new Edge(7,v5,v3);
    Edge* e8 = new Edge(8,v6,v3);
    Edge* e9 = new Edge(9,v6,v5);
    Edge* e10 = new Edge(5,v7,v8);
    Edge* e11 = new Edge(3,v8,v9);
    
    // set up graph 1
    Directed dg1;
    // add vertices to graph
    cout << "Adding vertices to graph 1..." << endl;
    dg1.addVertex(*v1);
    dg1.addVertex(*v2);
    dg1.addVertex(*v3);
    // add remaining vertices as an array
    Vertex* vArray = new Vertex[3] {*v4,*v5,*v6};
    dg1.addVertices(vArray,3);
    
    // add edges to graph
    cout << "\nAdding edges to graph 1..." << endl;
    dg1.addEdge(*e1);
    dg1.addEdge(*e2);
    dg1.addEdge(*e3);
    dg1.addEdge(*e4);
    dg1.addEdge(*e5);
    dg1.addEdge(*e6);
    dg1.addEdge(*e7);
    dg1.addEdge(*e8);
    dg1.addEdge(*e9);
    
    cout << endl;
    cout << dg1; // overloaded stream insertion
    cout << "\nString representation of the graph 1: ";
    cout << dg1.toString() << endl; // display the set of edges as a string

    
    // set up graph 2
    Directed dg2;
    // add vertices to graph
    cout << "Adding vertices to graph 2..." << endl;
    dg2.addVertex(*v7);
    dg2.addVertex(*v8);
    dg2.addVertex(*v9);
    
    // add edges to graph
    cout << "\nAdding edges to graph 2..." << endl;
    dg2.addEdge(*e10);
    dg2.addEdge(*e11);
    
    cout << endl;
    cout << dg2; // overloaded stream insertion
    cout << "\nString representation of the graph 2: ";
    cout << dg2.toString() << endl; // display the set of edges as a string
    
    // test overloaded relational operators
    cout << boolalpha << endl;
    cout << (dg1== dg2) << endl; // false
    Directed dg4;
    dg4 = dg2; // assignment operator
    cout << (dg4==dg2) << endl; // true
    cout << (dg1>dg2) << endl; // true
    cout << (dg2>dg1) << endl; // false
    
    // = and + operators
    Directed dg3;
    dg3 = (dg1 + dg2);
    cout << dg3;
   
    // pre and post increment
    // when on single line, dg3++ and ++dg3 should return same result
    ++dg4;
    cout << dg4; // edge weights will be incremented
    dg3++;
    cout << dg3; // edge weights will be incremented

    Directed dg5;
    dg5 = ++dg3; // increment dg3, then assign to dg5
    cout << dg5;
    dg5 = dg3++; // assign dg3, then increment dg3
    cout << dg5;

    cout << endl;
    
    return 0;
}
