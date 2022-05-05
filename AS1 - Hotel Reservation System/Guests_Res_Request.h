#ifndef GUESTS_RES_REQUEST_H
#define GUESTS_RES_REQUEST_H

#include "Guests.h"

class Guests_Res_Request {
private:
//attributes
    Guests *guests;
    int reservation_id;
    int num_nights;
    static int id_counter;
public:
    Guests_Res_Request(); // default constructor
    Guests_Res_Request(const Guests *g); // parametrized constructor
    Guests_Res_Request(const Guests_Res_Request &rhs); // copy constructor 
    ~Guests_Res_Request(); // destructor
    
    // getters
    int get_reservation_id() const;
    int get_num_nights() const;
    int get_check_in_day() const;
    int get_room_number() const;
    
    void print_guests_res_request() const; // print function for guest_res_request object
    
    
};

#endif
