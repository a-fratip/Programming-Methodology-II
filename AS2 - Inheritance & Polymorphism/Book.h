#ifndef BOOK_H
#define BOOK_H

#include "Reference.h"

#include <string>

class Book : public Reference {
private:
// defaults
    static constexpr int def_id = 0;
    static constexpr const char *def_title = "Unnamed title";
    static constexpr const char *def_author = "Unnamed author";
    static constexpr int def_year = 0;
    static constexpr const char *def_pub = "Unknown publisher";
    static constexpr int def_pages = 0;
protected:
// data members
    string pub;
    int num_pages;
public:
    Book(int id = def_id, string title = def_title, string author = def_author, int pub_year = def_year,
            string pub = def_pub, int num_pages = def_pages); // constructor 
    Book(const Book &rhs); // copy constructor
    virtual ~Book() = default; // destructor 
    
    // getters
    string get_pub() const;
    int getNumberOfPages() const;
    
    // setters
    void set_pub(string pub);
    void set_num_pages(int num_pages);
    
    virtual void print() const override; // print function for book class
    
};

#endif