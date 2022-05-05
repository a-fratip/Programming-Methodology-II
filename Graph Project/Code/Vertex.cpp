#include "Vertex.h"

int Vertex::id_counter = 0;

Vertex::Vertex(int value, string name)
    : value{value} , name{name}
    {
        id = ++id_counter;
    }
    
int Vertex::getID() const { return id; }

int Vertex::getValue() const { return value; }

string Vertex::getName() const { return name; }

vector <Edge>& Vertex::getEdgeList() { return edgeList; }

size_t Vertex::getDegree() const { return edgeList.size(); }

void Vertex::setValue(int value) { this->value = value; }

void Vertex::setName(string name) { this->name = name; }

void Vertex::addEdgetoEdgeList(Vertex* end, int weight) {
    Edge e(weight,end);
    edgeList.push_back(e);
    cout << "Edge between " << id << " and " << end->getID() << " successfully added" << endl;
}

void Vertex::printEdgeList() const {
    cout << "[";
    for (auto it = edgeList.begin(); it != edgeList.end(); it++) {
        cout << it->getEndID() << "(" << it->getWeight() << ") --> ";
    }
    cout << "]";
    cout << endl;
}

bool Vertex::operator==(const Vertex& rhs) const { // compare vertex ID's
    return id == rhs.id;
}

bool Vertex::operator!=(const Vertex& rhs) const {
    return !(*this == rhs);
}