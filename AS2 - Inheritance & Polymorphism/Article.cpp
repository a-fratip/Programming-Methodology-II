#include "Article.h"

#include <iostream>

using namespace std;

Article::Article(int id, string title, string author, int pub_year, string pub_location, int startPage, int endPage)
    : Reference(id, title, author, pub_year), pub_location{pub_location}, startPage{startPage}, endPage{endPage}
    {
        
    }
    
Article::Article(const Article &rhs)
    : Reference(rhs)
    {
        pub_location = rhs.pub_location;
        startPage = rhs.startPage;
        endPage = rhs.endPage;
    }
    
string Article::get_pub_location() const { return pub_location; }

int Article::get_start_page() const { return startPage; }

int Article::get_end_page() const { return endPage; }

int Article::getNumberOfPages() const {
    return endPage - startPage;
}

void Article::set_pub_location(string location) { pub_location = location; }

void Article::set_start_page(int start_page) {
    if (start_page > 0) {
        startPage = start_page;
        return;
    }
    cout << "Page numbers cannot be negative!" << endl;
}

void Article::set_end_page(int end_page) {
    if (end_page > startPage) {
        endPage = end_page;
        return;
    }
    cout << "End page must be after start page!" << endl;
}

void Article::print() const {
    Reference::print();
    cout << "Publication location: " << pub_location << endl;
    cout << "Start page: " << startPage << endl;
    cout << "End page: " << endPage << endl;
}
