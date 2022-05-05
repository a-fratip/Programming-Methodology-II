#include "Guests.h"

#include <iostream>

using namespace std;

Guests::Guests()
    : room_number{0}, num_guests{0}
    {
        check_in = new Date(3,1,2022); // default check in set to March 1
        check_out = new Date(3,8,2022); // default check out set to March 8
        guests_info = new Information[max_guests];
    }
    
Guests::Guests(const Guests &rhs) {
    check_in = new Date(*(rhs.check_in));
    check_out = new Date(*(rhs.check_out));
    room_number = rhs.room_number;
    num_guests = rhs.num_guests;
    guests_info = new Information[max_guests];
    for(int i = 0; i < num_guests; i++) {
        guests_info[i] = rhs.guests_info[i];
    }
}

Guests::~Guests() {
    delete check_in;
    delete check_out;
    delete [] guests_info;
}

int Guests::find_info(const char *first_name, const char *last_name) const {
    // loop through the array
    for (int i = 0; i < num_guests; i++) {
        // search for the guest by checking for the same name
        if (strcmp(guests_info[i].get_first_name(), first_name) == 0
            && strcmp(guests_info[i].get_last_name(), last_name) == 0) // names are equal
            {
                return i; // if found, return index where guest was found
            }
    }
    
    return -1; // -1 to indicate guest was not found
}

void Guests::add_info(const Information &info) {
    // if info is not already in array
    if (find_info(info.get_first_name(), info.get_last_name()) == -1) {
        // and if room is not at max capacity
        if (num_guests < max_guests)
        {
            guests_info[num_guests] = info; // add info to array
            num_guests++; // increment number of guests in the room
        }
        else // if room is at max capacity
        {
            cout << "Cannot add information. Number of guests in the room exceeded!" << endl;
        }
    }
    else if (find_info(info.get_first_name(), info.get_last_name()) != -1)  // info is already in the array
    {
        cout << "Cannot add duplicate information!" << endl;
    }
}

void Guests::remove_info(const char *first_name, const char *last_name) {
    int index = find_info(first_name,last_name); // -1 if not found
    // if info is in the array
    if (index != -1) {
        // loop through reduced array
        for (int i = index; i < num_guests-1; i++)
        {
            guests_info[i] = guests_info[i+1]; // shift elements of the array
        }
        num_guests--; // decrement the number of guests in the room
    }
    else // if info is not in the array
    {
        cout << "Information cannot be found!" << endl;
    }
}

void Guests::print_guests_info() const {
    cout << "---------------Guests staying in the room---------------" << endl;
    for (int i = 0; i < num_guests; i++) {
        cout << "Guest " << (i+1) << " information:" << endl << endl;
        guests_info[i].print_information();
        cout << endl;
    }
}

int Guests::get_check_in_month() const {
    return check_in->get_month();
}

int Guests::get_check_in_day() const {
    return check_in->get_day();
}

int Guests::get_check_in_year() const {
    return check_in->get_year();
}

int Guests::get_check_out_month() const {
    return check_out->get_month();
}

int Guests::get_check_out_day() const {
    return check_out->get_day();
}

int Guests::get_check_out_year() const {
    return check_out->get_year();
}

int Guests::get_room_number() const {
    return room_number;
}

void Guests::set_check_in_day(int day) {
    if (day >= 1 && day <= 8) // verify check in day
    {
        check_in->set_day(day);
        return;
    }
    
     // if invalid check in day
    cout << "Invalid check in day" << endl;
}

void Guests::set_check_out_day(int day) {
    if (day >= 1 && day <= 8) // verify check out day
    {
        check_out->set_day(day);
        return;
    }
     
     // if invalid check out day
    cout << "Invalid check out day" << endl;
}

void Guests::set_room_number(int room_num) {
    if (room_num >= 1 && room_num <= 20) // verify input
    {
        room_number = room_num;
        return;
    }
    // if not a valid room number
    cout << room_num << " is not a valid room number" << endl;
}

void Guests::print_guests() const {
    cout << "Check in date is ";
    check_in->print_date();
    cout << "Check out date is ";
    check_out->print_date();
    cout << "Room number is " << room_number << endl;
    print_guests_info();
    cout << endl;
}