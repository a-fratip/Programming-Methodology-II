#ifndef ARTICLE_H
#define ARTICLE_H

#include "Reference.h"

#include <string>

using namespace std;

class Article : public Reference {
private:
// default variables
    static constexpr int def_id = 0;
    static constexpr const char *def_title = "Unnamed title";
    static constexpr const char *def_author = "Unnamed author";
    static constexpr int def_year = 0;
    static constexpr const char *def_location = "Unknown location";
    static constexpr int def_page = 0;
protected:
// data members
    string pub_location;
    int startPage;
    int endPage;
public:
    Article(int id = def_id, string title = def_title, string author = def_author, int pub_year = def_year, 
                string pub_location = def_location, int startPage = def_page, int endPage = def_page); // constructor
    Article(const Article &rhs); // copy constructor
    virtual ~Article() = default; // destructor
    
    // getters
    string get_pub_location() const;
    int get_start_page() const;
    int get_end_page() const;
    int getNumberOfPages() const;
    
    // setters
    void set_pub_location(string location);
    void set_start_page(int start_page);
    void set_end_page(int end_page);
    
    virtual void print() const override; // overriden print function            
    
};

#endif