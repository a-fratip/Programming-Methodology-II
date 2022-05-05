#ifndef ELECTRONIC_DEVICE_H
#define ELECTRONIC_DEVICE_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class electronic_device {
protected:
    string brand;
    int serial_number;
    string color;
    double price;
public:
    electronic_device(string brand = "", int serial_number = 0, string color = "", double price = 0.0) // constructor
        : brand{brand}, serial_number{serial_number}, color{color}, price{price}
        {
            
        }
    virtual ~electronic_device() = default; //virtual destructor
    
    // getters
    string getBrand() const { return brand; }
    int getSerialNumber() const { return serial_number; }
    string getColor() const { return color; }
    double getPrice() const { return price; }
    
    // setters
    void setBrand(string brand) { this->brand = brand; }
    void setSerialNumber(int serial_number) { this->serial_number = serial_number; }
    void setColor(string color) { this->color = color; }
    void setPrice(double price) { this->price = price; }
    
    // virtual print function
    virtual void print() const {
        cout << "Brand: " << brand << endl;
        cout << "Serial number: " << serial_number << endl;
        cout << "Color: " << color << endl;
        cout << "Price: " << fixed << setprecision(2) << price << endl;
        cout << endl;
    }
    
};

#endif
