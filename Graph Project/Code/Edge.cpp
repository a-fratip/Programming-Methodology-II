#include "Edge.h"

Edge::Edge() 
    : weight{0}
    {
        end = new Vertex();
    }
    
Edge::Edge(int weight, Vertex* end)
    : weight{weight}
    {
        this->end = new Vertex(*end);
    }
    
Edge::Edge(const Edge& rhs)
    : weight{rhs.weight}
    {
        end = new Vertex(*rhs.end);
    }

Edge::~Edge() {
    delete end;
}

int Edge::getWeight() const { return weight; }

int Edge::getEndID() const { return end->getID(); }

int Edge::getEndValue() const { return end->getValue(); }

Vertex* Edge::getEnd() const { return end; }

void Edge::setWeight(int weight) { this->weight = weight; }

void Edge::setEndVertex(int value, string name) {
    end->setValue(value);
    end->setName(name);
}