#include "Book.h"

#include <iostream>

using namespace std;

Book::Book(int id, string title, string author, int pub_year, string pub, int num_pages)
    : Reference(id,title,author,pub_year), pub{pub}, num_pages{num_pages}
    {
        
    }

Book::Book(const Book &rhs) 
        : Reference(rhs) 
        {
            pub = rhs.pub;
            num_pages = rhs.num_pages;
        }
        
string Book::get_pub() const { return pub; }

int Book::getNumberOfPages() const { return num_pages; }

void Book::set_pub(string pub) { this->pub = pub; }

void Book::set_num_pages(int num_pages) { this->num_pages = num_pages; }

void Book::print() const {
    Reference::print();
    cout << "Publisher: " << pub << endl;
    cout << "Number of pages: " << num_pages << endl;
    
}