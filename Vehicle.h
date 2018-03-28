#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle {
    public:
        Vehicle(string, string, string, int, int);
    
        string getMake() const;
        string getModel() const;
        string getColour() const;
        int getYear() const;
        int getMilage() const;

	friend void operator<<(ostream&, const Vehicle*);
	bool operator<(const Vehicle*) const;
	bool operator>(const Vehicle*) const;

    private:
        string make;
        string model;
        string colour;
        int year;
        int mileage;
};

#endif
