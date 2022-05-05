#ifndef GUESTS_H
#define GUESTS_H

#include "Information.h"

class Guests {
private:
//attributes
    Date *check_in;
    Date *check_out;
    int room_number; // 1 to 20
    Information *guests_info; // array that keeps the information of all the guests in a room
    int num_guests;
    static constexpr int max_guests = 4; // maximum number of guests in a room
public:
    Guests(); // default constructor
    Guests(const Guests &rhs); // copy constructor
    ~Guests(); // destructor
    
    // helper functions to manage array
    int find_info(const char *first_name, const char *last_name) const; // searches the array for a guest's information
    void add_info(const Information &info); //adds information to the array
    void remove_info(const char *first_name, const char *last_name); // removes a guest's information from the array
    void print_guests_info() const; // prints the information of all the guests in a room
    
    // getters
    int get_check_in_month() const;
    int get_check_in_day() const;
    int get_check_in_year() const;
    int get_check_out_month() const;
    int get_check_out_day() const;
    int get_check_out_year() const;
    int get_room_number() const;
    
    // setters
    void set_check_in_day(int day);
    void set_check_out_day(int day);
    void set_room_number(int room_num);
    
    void print_guests() const; // print function for a guests object
    
};

#endif