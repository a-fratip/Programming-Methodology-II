#ifndef REFERENCE_H
#define REFERENCE_H

#include <string>

using namespace std;

class Reference {
private:
// default variables
    static constexpr int def_id = 0;
    static constexpr const char *def_title = "Unnamed title";
    static constexpr const char *def_author = "Unnamed author";
    static constexpr int def_year = 0;
protected:
// data members
    int id;
    string title;
    string author;
    int pub_year;
public:
    Reference(int id = def_id, string title = def_title, string author = def_author, int pub_year = def_year); // constructor
    Reference(const Reference &rhs); // copy constructor
    virtual ~Reference() = default; // destructor
    
    // getters 
    int get_id() const;
    string get_title() const;
    string get_author() const;
    int get_pub_year() const;
    
    // setters
    void set_id(int num);
    void set_title(string title);
    void set_author(string author);
    void set_pub_year(int year);
    
    virtual void print() const; // print function for reference class
    
};

#endif