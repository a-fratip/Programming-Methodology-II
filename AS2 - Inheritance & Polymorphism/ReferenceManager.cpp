#include "ReferenceManager.h"

#include <iostream>

using namespace std;

ReferenceManager::ReferenceManager()
    : numReferences{0}, capacity{0}
    {
        
    }
    
ReferenceManager::ReferenceManager(int capacity)
    : numReferences{0}, capacity{capacity}
    {
        references = new Reference*[capacity];
        for (int i = 0; i < capacity; i++)
        {
            references[i] = nullptr;
        }
    }
    
ReferenceManager::ReferenceManager(const ReferenceManager &rhs) {
    numReferences = rhs.numReferences;
    capacity = rhs.capacity;
    references = new Reference*[capacity];
    for (int i = 0; i < numReferences; i++)
    {
        references[i] = rhs.references[i];
    }
}

ReferenceManager::~ReferenceManager() {
    for (int i = 0; i < numReferences; i++) {
        delete references[i];
    }
    delete [] references;
}

bool ReferenceManager::add(Reference &ref) {
    if (numReferences < capacity) {
        references[numReferences] = &ref;
        numReferences++;
        return true; // reference successfully added
    }
    else
    {
        return false; // manager is full
    }
}

int ReferenceManager::get(int pos) const { return references[pos]->get_id(); } // assuming valid position is passed

bool ReferenceManager::Delete(int pos) {
    if (pos >= 0 && pos < numReferences) {
        for (int i = pos; i < numReferences - 1; i++)
        {
            references[i] = references[i+1];
        }
        numReferences--;
        
        return true; // element successfully removed
    }
    else
    {
        return false; // pos was not a valid index
    }
}

bool ReferenceManager::search(int id) const {
    for (int i = 0; i < numReferences; i++) {
        if (references[i]->get_id() == id)
        {
            return true; // reference with identifier id found
        }
    }
    
    return false; // reference with identifier id not found
}

void ReferenceManager::print_references() const {
    for (int i = 0; i < numReferences; i++) {
        references[i]->print();
        cout << endl;
    }
}
