#ifndef CELLPHONE_H
#define CELLPHONE_H

#include "electronic_device.h"

#include <iostream>
using namespace std;

class cellphone : public electronic_device {
protected:
    int number_of_cameras;
public:
    cellphone(string brand = "", int serial_number = 0, string color = "", double price = 0.0, int number_of_cameras = 0) // constructor
        : electronic_device(brand,serial_number,color,price), number_of_cameras{number_of_cameras}
        {
            
        }
    virtual ~cellphone() = default; // virtual destructor
    
    int getNumberOfCameras() const { return number_of_cameras; } // getter for additional attribute
    
    void setNumberOfCameras(int number_of_cameras) { this->number_of_cameras = number_of_cameras; } // setter for additional attribute
    
    // overriding base class print function
    virtual void print() const override {
        electronic_device::print();
        cout << "Number of cameras: " << number_of_cameras << endl;
        cout << endl;
    }
    
};

#endif