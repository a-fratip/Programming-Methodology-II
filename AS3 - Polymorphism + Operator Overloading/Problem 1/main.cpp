#include "Directed.h"

#include <iostream>
using namespace std;

int main() {
    
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
    
    //create directed graph
    Graph* dg = new Directed(); // empty graph
    
    // add vertices to graph
    cout << "Adding vertices to graph..." << endl;
    dg->addVertex(*v1);
    dg->addVertex(*v2);
    dg->addVertex(*v3);
    // add remaining vertices as an array
    Vertex* vArray = new Vertex[3] {*v4,*v5,*v6};
    dg->addVertices(vArray,3);
    
    // add edges to graph
    cout << "\nAdding edges to graph..." << endl;
    dg->addEdge(*e1);
    dg->addEdge(*e2);
    dg->addEdge(*e3);
    dg->addEdge(*e4);
    dg->addEdge(*e5);
    dg->addEdge(*e6);
    dg->addEdge(*e7);
    dg->addEdge(*e8);
    dg->addEdge(*e9);
    
    cout << endl;
    dg->display(); // display list of edges
    cout << "\nString representation of the graph: ";
    cout << dg->toString() << endl; // display the set of edges as a string 
    
    // remove vertex
    cout << "\nRemoving a vertex..." << endl;
    dg->removeVertex(*v1);
    cout << "Searching for removed vertex..." << endl;
    if (!(dg->searchVertex(*v1)))
        cout << "Vertex not found" << endl;
    // removing vertex v1 should also remove edges e1 and e2
    cout << "Searching for edges that have connection with removed vertex..." << endl;
    if (!(dg->searchEdge(*e1)))
        cout << "Edge not found" << endl;
    if (!(dg->searchEdge(*e2)))
        cout << "Edge not found" << endl;
        
    // remove edge
    cout << "\nRemoving an edge..." << endl;
    dg->removeEdge(*e5);
    cout << "Searching for removed edge..." << endl;
    if (!(dg->searchEdge(*e5)))
        cout << "Edge not found" << endl;
    // removing an edge should not remove connected vertices
    cout << "Searching for vertices connected to removed edge..." << endl;
    if (dg->searchVertex(*v2))
        cout << "Vertex still in graph" << endl;
    if (dg->searchVertex(*v5))
        cout << "Vertex still in graph" << endl;
        
    cout << "\nDisplaying graph after modifications..." << endl;
    dg->display(); 
    cout << "\nString representation of the graph: ";
    cout << dg->toString() << endl;
    
    cout << "\nNow cleaning the graph..." << endl;
    dg->clean();
    
    cout << endl;
    
    return 0;
}
