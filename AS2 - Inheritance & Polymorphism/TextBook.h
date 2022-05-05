#ifndef TEXTBOOK_H
#define TEXTBOOK_H

#include "Book.h"

#include <string>

class TextBook : public Book {
private:
// defaults
    static constexpr int def_id = 0;
    static constexpr const char *def_title = "Unnamed title";
    static constexpr const char *def_author = "Unnamed author";
    static constexpr int def_year = 0;
    static constexpr const char *def_pub = "Unknown publisher";
    static constexpr int def_pages = 0;
    static constexpr const char *def_url = " ";
protected:
// data member
    string URL;
public:
    TextBook(int id = def_id, string title = def_title, string author = def_author, int pub_year = def_year,
            string pub = def_pub, int num_pages = def_pages, string URL = def_url); // constructor
    TextBook(const TextBook &rhs); // copy constructor
    virtual ~TextBook() = default; // destructor
    
    // getter and setter
    string get_url() const;
    void set_url(string url);
    
    virtual void print() const override; // print function for textbook class
    
};

#endif