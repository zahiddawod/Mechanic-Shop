#include <sstream>
#include <iomanip>
#include <iostream>

#include "Vehicle.h"
using namespace std;
#include <string>

Vehicle::Vehicle(string ma, string mo, string col, int y, int m) { 
    make = ma;
    model = mo;
    colour = col;
    year = y;
    mileage = m;
}

string  Vehicle::getMake() const     { return make; }
string  Vehicle::getModel() const    { return model; }
string  Vehicle::getColour() const   { return colour; }
int     Vehicle::getYear() const     { return year; }
int     Vehicle::getMilage() const   { return mileage; }

void operator<<(ostream& output, const Vehicle* v) {
	output << "\t" << setw(7) << v->getColour() << " " 
                 << v->getYear() << " " << setw(17) << v->getMake() << " " << v->getModel() << " (" 
                 << v->getMilage() << "km)" << endl;
}

bool Vehicle::operator<(const Vehicle* v) const { return year < v->getYear(); }
bool Vehicle::operator>(const Vehicle* v) const { return year > v->getYear(); }
