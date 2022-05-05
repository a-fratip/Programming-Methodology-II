#ifndef REFERENCEMANAGER_H
#define REFERENCEMANAGER_H

#include "Reference.h"
#include "Article.h"
#include "Book.h"
#include "TextBook.h"

class ReferenceManager {
private:
// attributes
    Reference* *references; // array of pointers to Reference objects
    int numReferences; // current size of the array
    int capacity; // max size of the array
public:
    ReferenceManager(); // Default constructor
    ReferenceManager(int capacity); // Regular constructor
    ReferenceManager(const ReferenceManager &rhs); // Copy constructor
    ~ReferenceManager(); // Destructor
    
    // helper functions to manage array 
    bool add(Reference &ref); // adds a reference at the next available position
    int get(int pos) const; // returns the id of the reference stored at position pos
    bool Delete(int pos); // removes the element at position pos
    bool search(int id) const; // searches the array for a reference with identifier id
    void print_references() const; // displays the list of all references held in the array
    
};

#endif