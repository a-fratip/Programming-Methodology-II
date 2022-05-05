#include "Vertex.h"

int Vertex::id_counter = 0;

Vertex::Vertex(int value)
    : value{value}
    {
        id = ++id_counter;
    }
    
int Vertex::getID() const { return id; }

int Vertex::getValue() const { return value; }

void Vertex::setValue(int value) { this->value = value; }

