#ifndef INFORMATION_H
#define INFORMATION_H

#include "Date.h"

class Information {
private:
//attributes
    char *first_name; 
    char *last_name;
    Date *date_of_birth;
    
public:
    Information(); //default constructor
    Information(const char *first, const char *last, const Date *date_of_birth); //parametrized constructor
    Information(const Information &rhs); //copy constructor
    ~Information(); //destructor
    
    //getters
    char * get_first_name() const;
    char * get_last_name() const;
    int get_birth_month() const;
    int get_birth_day() const;
    int get_birth_year() const;
    
    //setters
    void set_first_name(const char *name);
    void set_last_name(const char *name);
    void set_date_of_birth(int month, int day, int year);
    
    void print_information() const; //print function for information objects
};

#endif