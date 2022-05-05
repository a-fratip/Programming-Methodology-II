#ifndef DATE_H
#define DATE_H

class Date {
private:
//attributes
    int month;
    int day;
    int year;
public:
    Date(int month = 0, int day = 0, int year = 0); //parametrized constructor
    ~Date() = default; // destructor
    
    //getters
    int get_month() const;
    int get_day() const;
    int get_year() const;
    
    //setters
    void set_month(int month);
    void set_day(int day);
    void set_year(int year);
    
    void print_date() const; //print function for date objects
    
};

#endif