#include "cellphone.h"
#include "laptop.h"
#include "smartwatch.h"

#include <fstream>
#include <iostream>
using namespace std;

int main() {
    // create dynamic objects of derived class using base class pointer
    cellphone* cp1 = new cellphone("Apple",110002,"blue",1000,3);
    laptop* lp1 = new laptop("Dell",22342,"black",800.5,5,false);
    smartwatch* sw1 = new smartwatch("Samsung",123456,"gray",600,24);
    laptop* lp2 = new laptop("Lenovo",23345,"black",1000,7,true);
    smartwatch* sw2 = new smartwatch("Apple",2324395,"gray",800,36);
    cellphone* cp2 = new cellphone("LG",345522,"silver",650,1);
    
    // create array of base class pointers and store created objects
    const int size = 6; 
    electronic_device* devices[size] = {cp1,lp1,sw1,lp2,sw2,cp2};
    
    // create output file and check if created successfully
    ofstream out_file{"../information.txt"}; // use ../ in codeLite IDE to specify proper directory
    if(!out_file) {
        cerr << "Error creating file!" << endl;
        return 1;
    }
    
    // loop through devices array
    for (int i = 0; i < size; i++) {
        cellphone* c = dynamic_cast<cellphone*>(devices[i]); // cast to cellphone
        // if cast is successful, write to file
        if (c != nullptr) {
            out_file << "cellphone " << c->getBrand() << " " << c->getSerialNumber()
                     << " " << c->getColor() << " " << c->getPrice() << " " << c->getNumberOfCameras() << endl;
        }
        
        laptop* l = dynamic_cast<laptop*>(devices[i]); // cast to laptop
        // if cast is successful, write to file
        if (l != nullptr ) {
            out_file << "laptop " << l->getBrand() << " " << l->getSerialNumber()
                     << " " << l->getColor() << " " << l->getPrice() 
                     << " " << l->getNumberOfCores() << " " << l->getTouchscreen() << endl;
        }
        
        smartwatch* s = dynamic_cast<smartwatch*>(devices[i]); // cast to smartwatch
        // if cast is successful, write to file
        if (s != nullptr) {
            out_file << "smartwatch " << s->getBrand() << " " << s->getSerialNumber()
                     << " " << s->getColor() << " " << s->getPrice() 
                     << " " << s->getBatteryLife() << endl;
        }
    }
    
    out_file.close();
    
    return 0;
}
