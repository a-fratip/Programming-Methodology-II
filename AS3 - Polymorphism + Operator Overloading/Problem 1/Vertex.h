#ifndef VERTEX_H
#define VERTEX_H

class Vertex {
private:
    static int id_counter; // creates unique vertex IDs
    int id; // store's a vertex's unique id
    int value; // a vertex's value
public:
    Vertex(int = 0); // constructor with vertex value -- default value set to 0
    
    // getters
    int getID() const;
    int getValue() const;
    
    // setters
    void setValue(int);
    
};

#endif