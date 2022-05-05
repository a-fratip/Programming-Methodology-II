#include "Reference.h"

#include <iostream>

using namespace std;

Reference::Reference(int id, string title, string author, int pub_year)
    : id{id}, title{title}, author{author}, pub_year{pub_year}
    {
        
    }
    
Reference::Reference(const Reference &rhs) {
    id = rhs.id;
    title = rhs.title;
    author = rhs.author;
    pub_year = rhs.pub_year;
}
    
int Reference::get_id() const {
    return id;
}

string Reference::get_title() const {
    return title;
}

string Reference::get_author() const {
    return author;
}

int Reference::get_pub_year() const {
    return pub_year;
}

void Reference::set_id(int num) {
    if (num > 0)
    {
        id = num;
        return;
    }
    cout << "ID cannot be negative!" << endl;
}

void Reference::set_title(string title) {
    this->title = title;
}

void Reference::set_author(string author) {
    this->author = author;
}

void Reference::set_pub_year(int year) {
    if (year > 0)
    {
        pub_year = year;
        return;
    }
    cout << "Year cannot be negative!" << endl;
}

void Reference::print() const {
    cout << "ID: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Publication year: " << pub_year << endl;
}