#include "Directed.h"
#include "Undirected.h"

#include <sstream>
#include <string>
#include <limits>

#include <iostream>
using namespace std;

// function prototype for user input validation
int validateIntegerInput(string);

int main() { 
    // an interactive driver application using a menu system
 
    string vname1, vname2;
    int value1, value2;
    int id1, id2, w;
    int option;
    int graph_selection;
    
    do {
        cout << "What type of graph do you want to create? (0=undirected/1=directed) ";
        cin >> graph_selection;
    } while (graph_selection != 0 && graph_selection != 1);
    
    Undirected udg;
    Directed dg;
    
    do {
        cout << "1. Add Vertex" << endl;
        cout << "2. Remove Vertex" << endl;
        cout << "3. Add Edge" << endl;
        cout << "4. Remove Edge" << endl;
        cout << "5. Search if a value is conatined by any of the graph's vertices" << endl;
        cout << "6. Search for an edge, if it exists in the graph" << endl;
        cout << "7. Print the path from a starting vertex" << endl;
        cout << "8. Print All Possible Paths of Graph" << endl;
        cout << "-1. Exit Program" << endl;
        
        cout << "Select which operation you want to perform (-1 to exit): ";

        cin >> option;
        Vertex* v1 = new Vertex();

        switch (option) {
            case -1:
                break;
                
            case 1:
                cout << "Add Vertex Operation -" << endl;
             //   cout << "Enter vertex value: ";
             //   cin >> value1;
                value1 = validateIntegerInput("vertex value");
                cout << "Enter vertex name: ";
                cin >> vname1;
                v1->setValue(value1);
                v1->setName(vname1);
                if (graph_selection == 0)
                    udg.addVertex(*v1);
                else if (graph_selection == 1)
                    dg.addVertex(*v1);

                break;

            case 2:
                cout << "Delete Vertex Operation -" << endl;
                cout << "Enter Name of Vertex to Delete : ";
                cin >> vname1;
                if (graph_selection == 0) {
                    Vertex temp1 = udg.getVertexByName(vname1);
                    udg.removeVertex(temp1);
                }
                else if (graph_selection == 1) {
                    Vertex temp2 = dg.getVertexByName(vname1);
                    dg.removeVertex(temp2);
                }
            
                break;

            case 3:
                cout << "Add Edge Operation -" << endl;
                cout << "Enter Name of Source Vertex: ";
                cin >> vname1;
                
                cout << "Enter Name of Destination Vertex: ";
                cin >> vname2;
              //  cout << "Enter Weight of Edge: ";
              //  cin >> w;
                w = validateIntegerInput("weight of edge");
                
                if (graph_selection == 0) {
                    Vertex* v2 = new Vertex(udg.getVertexByName(vname1));
                    Vertex* v3 = new Vertex(udg.getVertexByName(vname2));
                    udg.addEdge(v2,v3,w);
                    delete v2;
                    delete v3;
                }
                else if (graph_selection == 1) {
                    Vertex* v4 = new Vertex(dg.getVertexByName(vname1));
                    Vertex* v5 = new Vertex(dg.getVertexByName(vname2));
                    dg.addEdge(v4,v5,w);
                    delete v4;
                    delete v5;
                }

                break;

            case 4:
                cout << "Delete Edge Operation -" << endl;
                cout << "Enter Name of Source Vertex: ";
                cin >> vname1;
                
                cout << "Enter Name of Destination Vertex: ";
                cin >> vname2;
                
                if (graph_selection == 0) {
                    Vertex from = udg.getVertexByName(vname1);
                    Vertex to = udg.getVertexByName(vname2);
                    udg.removeEdge(from,to);
                }
                else if (graph_selection == 1) {
                    Vertex source = dg.getVertexByName(vname1);
                    Vertex destination = dg.getVertexByName(vname2);
                    dg.removeEdge(source,destination);
                }

                break;

            case 5:
                cout << "Search vertex value operation -" << endl;
              //  cout << "Enter vertex value to search for: ";
              //  cin >> value2;
                value2 = validateIntegerInput("vertex value to search for");
                if (graph_selection == 0) {
                    udg.searchVertexValue(value2);
                }
                else if (graph_selection == 1) {
                    dg.searchVertexValue(value2);
                }

                break;

            case 6:
                cout << "Search edge operation -" << endl;
                cout << "Enter Name of Source Vertex: ";
                cin >> vname1;
                cout << "Enter Name of Destination Vertex: ";
                cin >> vname2;
                if (graph_selection == 0) {
                    Vertex temp3 = udg.getVertexByName(vname1);
                    Vertex temp4 = udg.getVertexByName(vname2);
                    udg.searchEdge(temp3,temp4);
                }
                else if (graph_selection == 1) {
                    Vertex temp5 = dg.getVertexByName(vname1);
                    Vertex temp6 = dg.getVertexByName(vname2);
                    dg.searchEdge(temp5,temp6);
                }
                
                break;

            case 7:
                cout << "Print possible paths from starting vertex -" << endl;
              //  cout << "Enter starting vertex ID: ";
              //  cin >> id1;
                id1 = validateIntegerInput("starting vertex ID");
                if (graph_selection == 0)
                    udg.printNeighbourhoodByID(id1);
                else if (graph_selection == 1)
                    dg.printNeighbourhoodByID(id1);
                

                break;

            case 8:
                cout << "Print Graph Operation -" << endl;
                if (graph_selection == 0) {
                    udg.printGraph();
                }
                if (graph_selection == 1) {
                    dg.printGraph();
                }

                break;

            default:
                cout << "Enter Proper Option number " << endl;
        }
        
        cout << endl;

    } while (option != -1);

/*
    // Driver application to test overloaded operators of a directed graph
    
    // creates vertices
    Vertex* v1 = new Vertex(1,"Bert"); // deafult constructor will initialize value to 0
    // initialize vertices with values
    Vertex* v2 = new Vertex(2,"Sara");
    Vertex* v3 = new Vertex(3,"Tom");
    Vertex* v4 = new Vertex(4,"Ben");
    Vertex* v5 = new Vertex(5,"Bob");
    Vertex* v6 = new Vertex(6,"Karen");
    Vertex* v7 = new Vertex(7,"Pam");
    
    // set up graph 1
    Directed dg1;
    // add vertices to graph
    cout << "Adding vertices to graph 1..." << endl;
    dg1.addVertex(*v1);
    dg1.addVertex(*v2);
    dg1.addVertex(*v3);
    dg1.addVertex(*v4);
    
    // add edges to graph
    cout << "\nAdding edges to graph 1..." << endl;
    dg1.addEdge(v1,v2,1);
    dg1.addEdge(v3,v2,2);
    dg1.addEdge(v4,v2,5);
    dg1.addEdge(v1,v3,4);
    dg1.addEdge(v1,v4,7);
    dg1.addEdge(v4,v1,2);
    dg1.addEdge(v3,v4,1);
    dg1.addEdge(v2,v4,69);

    
    cout << endl;
    cout << dg1; // overloaded stream insertion

    // set up graph 2
    Directed dg2;
    // add vertices to graph
    cout << "Adding vertices to graph 2..." << endl;
    dg2.addVertex(*v5);
    dg2.addVertex(*v6);
    dg2.addVertex(*v7);
    
    // add edges to graph
    cout << "\nAdding edges to graph 2..." << endl;
    dg2.addEdge(v5,v6,1);
    dg2.addEdge(v6,v7,1);
    
    cout << endl;
    cout << dg2; // overloaded stream insertion
    
    // test overloaded relational operators
    cout << boolalpha << endl;
    cout << (dg1 == dg2) << endl; // false
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
    
    cout << ++dg5;
    cout << dg5++;

    cout << endl;
*/
/*
    // Driver application to test overloaded operators of an undirected graph
    
    // creates vertices
    Vertex* v1 = new Vertex(1,"CGY"); // deafult constructor will initialize value to 0
    // initialize vertices with values
    Vertex* v2 = new Vertex(2,"EDM");
    Vertex* v3 = new Vertex(3,"WPG");
    Vertex* v4 = new Vertex(4,"VAN");
    Vertex* v5 = new Vertex(5,"MTL");
    Vertex* v6 = new Vertex(6,"TOR");
    Vertex* v7 = new Vertex(7,"OTT");
    
    // set up graph 1
    Undirected udg1;
    // add vertices to graph
    cout << "Adding vertices to graph 1..." << endl;
    udg1.addVertex(*v1);
    udg1.addVertex(*v2);
    udg1.addVertex(*v3);
    udg1.addVertex(*v4);
    
    // add edges to graph
    cout << "\nAdding edges to graph 1..." << endl;
    udg1.addEdge(v1,v2,1);
    udg1.addEdge(v1,v3,2);
    udg1.addEdge(v1,v4,5);
    udg1.addEdge(v2,v3,4);
    udg1.addEdge(v2,v4,7);
    udg1.addEdge(v3,v4,2);
    
    cout << endl;
    cout << udg1; // overloaded stream insertion

    // set up graph 2
    Undirected udg2;
    // add vertices to graph
    cout << "Adding vertices to graph 2..." << endl;
    udg2.addVertex(*v5);
    udg2.addVertex(*v6);
    udg2.addVertex(*v7);
    
    // add edges to graph
    cout << "\nAdding edges to graph 2..." << endl;
    udg2.addEdge(v5,v6,1);
    udg2.addEdge(v5,v7,1);
    udg2.addEdge(v6,v7,1);
    
    cout << endl;
    cout << udg2; // overloaded stream insertion
    
    // test overloaded relational operators
    cout << boolalpha << endl;
    cout << (udg1 == udg2) << endl; // false
    Undirected udg4;
    udg4 = udg2; // assignment operator
    cout << (udg4==udg2) << endl; // true
    cout << (udg1>udg2) << endl; // true
    cout << (udg2>udg1) << endl; // false
    
    // = and + operators
    Undirected udg3;
    udg3 = (udg1 + udg2);
    cout << udg3;
   
    // pre and post increment
    // when on single line, dg3++ and ++dg3 should return same result
    ++udg4;
    cout << udg4; // edge weights will be incremented
    udg3++;
    cout << udg3; // edge weights will be incremented

    Undirected udg5;
    udg5 = ++udg3; // increment dg3, then assign to dg5
    cout << udg5;
    udg5 = udg3++; // assign dg3, then increment dg3
    cout << udg5;
    
    cout << ++udg5;
    cout << udg5++;

    cout << endl;
*/    
    return 0;
}

// function definition for user validation
int validateIntegerInput(string message) {
    int value{};
    string input;
    bool done = false;
    do {
        cout << "Enter an integer value for the " << message << ": ";
        cin >> input;
        istringstream validator{input}; // connect input to string stream
        if (validator >> value) { // check if extraction was successful
            if (value > 0) // check if integer is positive
                done = true;
            else
                cout << "Value cannot be negative!" << endl;
        }
        else
            cout << "You entered an invalid value!" << endl; // user did not enter an integer
        
        // discard input buffer
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        
    } while (!done);
    
    return value;
}
