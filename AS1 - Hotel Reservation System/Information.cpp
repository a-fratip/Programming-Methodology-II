#include "Information.h"

#include <iostream>
#include <string.h>

Information::Information()
    {
        first_name = new char[2];
        last_name = new char[2];
        std::strcpy(first_name, " ");
        std::strcpy(last_name, " ");
        date_of_birth = new Date();
    }
    
Information::Information(const char *first, const char *last, const Date *date_of_birth)
    {
        first_name = new char[std::strlen(first)+1];
        last_name = new char[std::strlen(last)+1];
        std::strcpy(first_name, first);
        std::strcpy(last_name, last);
        this->date_of_birth = new Date(*date_of_birth);
    } 
    
Information::Information(const Information &rhs) 
    {
        first_name = new char[std::strlen(rhs.first_name)+1];
        last_name = new char[std::strlen(rhs.last_name)+1];
        std::strcpy(first_name, rhs.first_name);
        std::strcpy(last_name, rhs.last_name);
        date_of_birth = new Date(*(rhs.date_of_birth));
    }
    
Information::~Information() {
    delete [] first_name;
    delete [] last_name;
    delete date_of_birth;
}

char * Information::get_first_name() const {
    return first_name;
}

char * Information::get_last_name() const {
    return last_name;
}

int Information::get_birth_month() const {
    return date_of_birth->get_month();
}

int Information::get_birth_day() const {
    return date_of_birth->get_day();
}

int Information::get_birth_year() const {
    return date_of_birth->get_year();
}

void Information::set_first_name(const char *name) {
    first_name = new char[std::strlen(name)+1];
    std::strcpy(first_name, name);
}

void Information::set_last_name(const char *name) {
    last_name = new char[std::strlen(name)+1];
    std::strcpy(last_name, name);
}

void Information::set_date_of_birth(int month, int day, int year) {
    date_of_birth->set_month(month);
    date_of_birth->set_day(day);
    date_of_birth->set_year(year);
}

void Information::print_information() const {
    std::cout << "First name is ";
    for(size_t i = 0; i < std::strlen(first_name); i++)
    {
        std::cout << first_name[i];
    }
    std::cout << std::endl;
    
    std::cout << "Last name is ";
    for(size_t i = 0; i < std::strlen(last_name); i++)
    {
        std::cout << last_name[i];
    }
    std::cout << std::endl;
    
    std::cout << "Date of birth is ";
    date_of_birth->print_date();
}