#include "TextBook.h"

#include <iostream>

using namespace std;

TextBook::TextBook(int id, string title, string author, int pub_year, string pub, int num_pages, string URL)
    : Book(id,title,author,pub_year,pub,num_pages), URL{URL}
    {
        
    }

TextBook::TextBook(const TextBook &rhs)
        : Book(rhs)
        {
            URL = rhs.URL;
        }
        
string TextBook::get_url() const { return URL; }

void TextBook::set_url(string URL) { this->URL = URL; }

void TextBook::print() const {
    Book::print();
    cout << "URL: " << URL << endl;
}