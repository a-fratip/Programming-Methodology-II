#ifndef LAPTOP_H
#define LAPTOP_H

#include "electronic_device.h"

#include <iostream>
using namespace std;

class laptop : public electronic_device {
protected:
    int number_of_cores;
    bool touchscreen;
public:
    laptop(string brand = "", int serial_number = 0, string color = "", double price = 0.0, int number_of_cores = 0, bool touchscreen = false) // constructor
        : electronic_device(brand,serial_number,color,price), number_of_cores{number_of_cores}, touchscreen{touchscreen}
        {
            
        }
    virtual ~laptop() = default; // virtual destructor
    
    int getNumberOfCores() const { return number_of_cores; } // getter for additional attribute
    bool getTouchscreen() const { return touchscreen; }
    
    void setNumberOfCores(int number_of_cores) { this->number_of_cores = number_of_cores; } // setter for additional attribute
    void setTouchscreen(bool touchscreen) { this->touchscreen = touchscreen; }
    
    // overriding base class print function
    virtual void print() const override {
        electronic_device::print();
        cout << "Number of cores: " << number_of_cores << endl;
        cout << "Touchscreen (0/1): " << touchscreen << endl;
        cout << endl;
    }
    
};

#endif