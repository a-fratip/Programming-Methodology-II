#include "Reservation_Manager.h"

#include <iostream>

using namespace std;

int main()
{
    cout << "---------------Test 1---------------" << endl;
    cout << "Creating a date object dynamically..." << endl;
    Date *d1 = new Date(1,28,2022);
    d1->print_date(); // test print function
    // test setters and getters
    cout << "Updating date..." << endl;
    d1->set_month(5);
    d1->set_day(11);
    d1->set_year(2002);
    cout << "Month = " << d1->get_month() << endl;
    cout << "Day = " << d1->get_day() << endl;
    cout << "Year = " << d1->get_year() << endl;
    // test print function
    cout << "Information about the date: "; 
    d1->print_date();
    cout << endl;
   
    cout << "---------------Test 2---------------" << endl;
    cout << "Creating an information object dynamically..." << endl;
    Information *i1 = new Information("Anthony", "Fratipietro", d1);
    i1->print_information(); // test print function
    cout << "Creating a default object.." << endl;
    Information *i2 = new Information();
    i2->print_information();
    // test getters and setters
    cout << "Updating information..." << endl;
    i2->set_first_name("Charles");
    i2->set_last_name("Vanderlay");
    i2->set_date_of_birth(1,7,2001);
    cout << "First name = " << i2->get_first_name() << endl;
    cout << "Last name = " << i2->get_last_name() << endl;
    cout << "Birth month = " << i2->get_birth_month() << endl;
    cout << "Birth day = " << i2->get_birth_day() << endl;
    cout << "Birth year = " << i2->get_birth_year() << endl;
    cout << "Creating new information object using copy constructor..." << endl;
    Information *i3 = new Information(*i2); //test copy constructor
    i3->print_information();
    cout << endl;
    
    cout << "---------------Test 3---------------" << endl;
    cout << "Creating a default guests object dynamically..." << endl;    
    Guests *g1 = new Guests();
    // test getters
    cout << "Check in month = " << g1->get_check_in_month() << endl;
    cout << "Check in day = " << g1->get_check_in_day() << endl;
    cout << "Check in year = " << g1->get_check_in_year() << endl;
    cout << "Check out month = " << g1->get_check_out_month() << endl;
    cout << "Check out year = " << g1->get_check_out_year() << endl;
    cout << "Room number = " << g1->get_room_number() << endl;
    // test setters
    cout << "Updating values..." << endl;
    g1->set_check_in_day(3);
    g1->set_check_out_day(7);
    g1->set_room_number(2);
    g1->print_guests(); // test print function 
    // test array functions
    cout << "Adding guest..." << endl;
    g1->add_info(*i1);
    cout << "Adding another guest..." << endl;
    g1->add_info(*i2);
    g1->print_guests_info();
    cout << "Trying to add the same guest..." << endl;
    g1->add_info(*i3);
    cout << "Removing second guest..." << endl;
    g1->remove_info("Charles","Vanderlay");
    cout << "Trying to remove unidentified guest..." << endl;
    g1->remove_info("Jane","Doe");
    g1->print_guests_info();
    cout << "Updating and adding another guest's information..." << endl;
    i3->set_first_name("Michael");
    i3->set_last_name("Scott");
    i3->set_date_of_birth(2,3,1993);
    g1->add_info(*i3);
    cout << "Information after modifications..." << endl;
    g1->print_guests();
    cout << endl;
    
    
    cout << "---------------Test 4---------------" << endl;
    cout << "Creating a reservation request for the guests..." << endl;
    Guests_Res_Request *r1 = new Guests_Res_Request(g1);
    r1->print_guests_res_request(); // test print function
    cout << "More guests are arriving..." << endl;
    cout << "Getting their information and creating a reservsation request" << endl;
    Date *d2 = new Date(12, 23, 2000);
    Date *d3 = new Date(11, 27, 20001);
    Date *d4 = new Date(6,26,1957);
    Information *i4 = new Information("Jim","Halpert", d2);
    Information *i5 = new Information("Pam","Beasly",d3);
    Information *i6 = new Information("Dwight","Schrute",d4);
    Guests *g2 = new Guests();
    g2->add_info(*i4);
    g2->add_info(*i5);
    g2->add_info(*i6);
    g2->set_check_in_day(4);
    g2->set_check_out_day(6);
    g2->set_room_number(5);
    Guests_Res_Request *r2 = new Guests_Res_Request(g2);
    r2->print_guests_res_request();
    cout << endl;
    
    cout << "---------------Test 5---------------" << endl;
    cout << "Reservation mananger created...." << endl;
    Reservation_Manager *rm = new Reservation_Manager();
    // test helper functions
    rm->add_request(*r1);
    rm->add_request(*r2);
    cout << "Both requests were added and are now being processed..." << endl;
    rm->process_request(*r1);
    rm->process_request(*r2);
    rm->print_reservation_manager();
    cout << "Details of second reservation..." << endl;
    rm->print_reservation(2);
    cout << "Now canceling this reservation..." << endl;
    rm->cancel_reservation(2);
    cout << "Reservation array after canacellation..." << endl;
    rm->print_res_arr();
    cout << "Now trying to print and cancel the reservation that was just cancelled..." << endl;
    rm->print_reservation(2);
    rm->cancel_reservation(2);
    cout << "Requests after cancellation..." << endl;
    rm->print_all_requests();
    cout << "Creating a copy of the request..." << endl;
    Guests_Res_Request *r3 = new Guests_Res_Request(*r1);
    cout << "Processing this request..." << endl;
    rm->process_request(*r3);
    cout << endl;
    
    delete rm;
    
    return 0;
}



