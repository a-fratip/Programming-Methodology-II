#include "Vertex.h"

int Vertex::id_counter = 0;

Vertex::Vertex(int value)
    : value{value}
    {
        id = ++id_counter;
    }
    
Vertex::Vertex(const Vertex& rhs)
    : id{rhs.id}, value{rhs.value}
    {
        
    }

int Vertex::getID() const { return id; }

int Vertex::getValue() const { return value; }

void Vertex::setValue(int value) { this->value = value; }

bool Vertex::operator==(const Vertex& rhs) const {
    return (id == rhs.id);
}

bool Vertex::operator!=(const Vertex& rhs) const {
    return !(*this == rhs);
}