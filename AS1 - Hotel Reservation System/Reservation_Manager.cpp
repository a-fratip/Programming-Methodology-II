#include "Reservation_Manager.h"

#include <iostream>

using namespace std;

Reservation_Manager::Reservation_Manager()
    : num_requests{0}
    {
        arr = new Guests_Res_Request[max_requests];
        for (int i = 0; i < max_no_of_nights; i++) {
            for (int j = 0; j < no_of_rooms; j++)
            {
                res_arr[i][j] = 0;
            }
        }
    }

Reservation_Manager::Reservation_Manager(const Reservation_Manager &rhs) {
    num_requests = rhs.num_requests;
    arr = new Guests_Res_Request[max_requests];
    for (int i = 0; i < num_requests; i++) {
        arr[i] = rhs.arr[i];
    }
    for (int i = 0; i < max_no_of_nights; i++) {
        for (int j = 0; j < no_of_rooms; j++)
        {
            res_arr[i][j] = rhs.res_arr[i][j];
        }
    }
}    
Reservation_Manager::~Reservation_Manager() 
{
    delete [] arr;
}

int Reservation_Manager::find_request(int id) const {
// search the requests array for the same reservation id
// if found, return array index
// if not found, return -1
    for (int i = 0; i < num_requests; i++) {
        if (arr[i].get_reservation_id() == id)
        {
            return i;
        }
    }
    return -1;
}

void Reservation_Manager::add_request(const Guests_Res_Request &r) {
// first check if the request is already in the array
    int index = find_request(r.get_reservation_id());
    // if not found
    if (index == -1) {
        if (num_requests < max_requests) // make sure that max requests have not been exceeded
        {
            arr[num_requests] = r; // add request to the array
            num_requests++;
        }
        else // max requests has been reached
        {
            cout << "Sorry, cannot take any more reservation requests" << endl;
        }
    }
    else if (index != -1) // request is already in the array
    {
        cout << "A reservation request with this id already exists!" << endl;
    }
}

void Reservation_Manager::remove_request(int id) {
// first check if the array contains a request with the corresponding id
    int index = find_request(id);
    // if found, remove request from array
    if (index != -1) {
        for (int i = index; i < num_requests-1; i++)
        {
            arr[i] = arr[i+1];
        }
        num_requests--;
        return;
    }
    // if not found
    cout << "Reservation request with this id cannot be found!" << endl;
}

void Reservation_Manager::print_all_requests() const {
    for (int i = 0; i < num_requests; i++) {
        cout << "Request " << (i+1) << " information:" << endl << endl;
        arr[i].print_guests_res_request();
        cout << endl;
    }
}

int Reservation_Manager::check_request(const Guests_Res_Request &r) const {
// checks if reservation is successful
// if successful, return reservation id
// if not successful, return -1
    int status = -1;
    int column_index = r.get_room_number() - 1;
    int row_index = r.get_check_in_day() - 1;
    for (int i = row_index, j = column_index; i < row_index + r.get_num_nights(); i++) {
        if (res_arr[i][j] != 0)
        {
            return status;
        }
    }
    
    return r.get_reservation_id();
}

void Reservation_Manager::process_request(const Guests_Res_Request &r) {
// check if request is successful
    int id = check_request(r);
    if (id == -1) // if not successful
    {
        cout << "Reservation was not successful" << endl;
        remove_request(r.get_reservation_id()); // remove request from array of requests
        return;
    }
    // if successful
    cout << "Reservation was successful" << endl;
    int column_index = r.get_room_number() - 1;
    int row_index = r.get_check_in_day() - 1;
    // add reservation id to 2d array
    for (int i = row_index, j = column_index; i < row_index + r.get_num_nights(); i++) {
        res_arr[i][j] = id;
    }
}

void Reservation_Manager::print_reservation(int id) const {
// first search the requests array for request with corresponding id
    int index = find_request(id);
    // if found, print results
    if (index != -1) {
        cout << "---------------Reservation Details---------------" << endl;
        arr[index].print_guests_res_request();
    }
    else // if not found
    {
        cout << "Sorry, can't find that reservation" << endl;
    }
}

void Reservation_Manager::cancel_reservation(int id) {
// first search the requests array for the request with the corresponding id
    int index = find_request(id);
    // if found
    if (index != -1) {
        int column_index = arr[index].get_room_number() -1;
        int row_index = arr[index].get_check_in_day() - 1;
        for (int i = row_index, j = column_index; i < row_index + arr[index].get_num_nights(); i++)
        {
            res_arr[i][j] = 0; // set corresponding elements in 2d array back to 0
        }
        remove_request(id); // remove request from requests array
    }
    else // if not found
    {
        cout << "It seems there is no reservation under that id" << endl;
    }
}

void Reservation_Manager::print_res_arr() const {
    for (int i = 0; i < max_no_of_nights; i++) {
        for (int j = 0; j < no_of_rooms; j++)
        {
            cout << res_arr[i][j] << " ";
        }
        cout << endl;
    }
}

void Reservation_Manager::print_reservation_manager() const {
    cout << "---------------Reservation Requests---------------" << endl;
    print_all_requests();
    cout << "---------------Reservation Array---------------" << endl;
    print_res_arr();
    cout << endl;
}