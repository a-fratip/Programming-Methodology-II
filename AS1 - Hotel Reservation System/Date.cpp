#include "Date.h"

#include <iostream>

Date::Date(int month, int day, int year)
    : month{month}, day{day}, year{year}
    {
        
    }
    
int Date::get_month() const {
    return month;
}

int Date::get_day() const {
    return day;
}

int Date::get_year() const {
    return year;
}

void Date::set_month(int month) {
    if (month >= 1 && month <= 12)
    {
        this->month = month;
        return;
    }
    
    std::cout << "This is not a valid month!" << std::endl;
}

void Date::set_day(int day) {
    if (day >= 1 && day <= 31)
    {
        this->day = day;
        return;
    }
    
    std::cout << "This is not a valid day!" << std::endl;
}

void Date::set_year(int year) {
    if (year > 0)
    {
        this->year = year;
        return;
    }
    
    std::cout << "This is not a valid year!" << std::endl;
}

void Date::print_date() const {
    std::cout << "Date (month/day/year) " 
        << month << "/" << day << "/" << year << std::endl;
}
    