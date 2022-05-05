#include "Edge.h"

Edge::Edge() 
    : weight{0}
    {
        start = new Vertex();
        end = new Vertex();
    }
    
Edge::Edge(int weight, Vertex* start, Vertex* end)
    : weight{weight}
    {
        this->start = new Vertex(*start);
        this->end = new Vertex(*end);
    }
    
Edge::Edge(const Edge& rhs)
    : weight{rhs.weight}
    {
        start = new Vertex(*rhs.start);
        end = new Vertex(*rhs.end);
    }

Edge::~Edge() {
  //  delete start;
  //  delete end;
}

int Edge::getWeight() const { return weight; }

int Edge::getStartID() const { return start->getID(); }

int Edge::getStartValue() const { return start->getValue(); }

int Edge::getEndID() const { return end->getID(); }

int Edge::getEndValue() const { return end->getValue(); }

Vertex* Edge::getStart() const { return start; }

Vertex* Edge::getEnd() const { return end; }

void Edge::setWeight(int weight) { this->weight = weight; }

void Edge::setStartVertex(int value) {
    start->setValue(value);
}

void Edge::setEndVertex(int value) {
    end->setValue(value);
}