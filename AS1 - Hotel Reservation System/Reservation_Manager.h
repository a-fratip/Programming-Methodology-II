#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H

#include "Guests_Res_Request.h"

class Reservation_Manager {
private:
// attributes
    static constexpr int max_no_of_nights = 7;
    static constexpr int no_of_rooms = 20;
    Guests_Res_Request *arr; // pointer to array of guest requests
    int num_requests;
    static constexpr int max_requests = 140; // 7 days * 20 rooms
    int res_arr[max_no_of_nights] [no_of_rooms]; // 2-D array to store reservation IDs
public:
    Reservation_Manager(); // default constructor
    Reservation_Manager(const Reservation_Manager &rhs);
    ~Reservation_Manager(); // destructor 
    
    // helper functions to manage requests array
    int find_request(int id) const;
    void add_request(const Guests_Res_Request &r);
    void remove_request(int id);
    void print_all_requests() const;
    
    //helper functions to manage 2D array
    int check_request(const Guests_Res_Request &r) const; // checks if a request is successful
    void process_request(const Guests_Res_Request &r); // process reservation after checking if successful
    void print_reservation(int id) const; // print details of reservation
    void cancel_reservation(int id); // removes reservation request from requests array and removes id from 2d array
    void print_res_arr() const; // display 2d array
    
    void print_reservation_manager() const; // print function for reservation manager class
};

#endif