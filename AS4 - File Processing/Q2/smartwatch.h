#ifndef SMARTWATCH_H
#define SMARTWATCH_H

#include "electronic_device.h"

#include <iostream>
using namespace std;

class smartwatch : public electronic_device {
protected:
    int battery_life;
public:
    smartwatch(string brand = "", int serial_number = 0, string color = "", double price = 0.0, int battery_life = 0) // constructor
        : electronic_device(brand,serial_number,color,price), battery_life{battery_life}
        {
            
        }
    virtual ~smartwatch() = default; // virtual destructor
    
    int getBatteryLife() const { return battery_life; } // getter for additional attribute
    
    void setBatteryLife(int battery_life) { this->battery_life = battery_life; } // setter for additional attribute
    
    // overriding base class print function
    virtual void print() const override {
        electronic_device::print();
        cout << "Battery life: " << battery_life << "%" << endl;
        cout << endl;
    }
    
};

#endif