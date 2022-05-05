#include "Guests_Res_Request.h"

#include <iostream>

using namespace std;

int Guests_Res_Request::id_counter = 0;

Guests_Res_Request::Guests_Res_Request()
    : reservation_id{0}, num_nights{0}, guests{nullptr}
    {
        
    }
    
Guests_Res_Request::Guests_Res_Request(const Guests *g) {
    reservation_id = ++id_counter;
    num_nights = g->get_check_out_day() - g->get_check_in_day();
    guests = new Guests(*g);
}

Guests_Res_Request::Guests_Res_Request(const Guests_Res_Request &rhs) {
    reservation_id = rhs.reservation_id;
    num_nights = rhs.num_nights;
    guests = new Guests(*(rhs.guests));
}

Guests_Res_Request::~Guests_Res_Request() {
    delete guests;
}

int Guests_Res_Request::get_reservation_id() const {
    return reservation_id;
}

int Guests_Res_Request::get_num_nights() const {
    return num_nights;
}

int Guests_Res_Request::get_check_in_day() const {
    return guests->get_check_in_day();
}

int Guests_Res_Request::get_room_number() const {
    return guests->get_room_number();
}

void Guests_Res_Request::print_guests_res_request() const {
    cout << "Reservation ID: " << reservation_id << endl;
    cout << "Guests are staying for " << num_nights << " nights" << endl;
    guests->print_guests();
}