#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Vehicle.h"
#include "VehicleList.h"
#include "Person.h"

using namespace std;

class Customer : Person {
    public:
        Customer(string="", string="", string="", string="");

	int getId() const;
        int getNumVehicles() const;
        VehicleList& getVehicles();
        
	void operator+=(Vehicle*);
	friend void operator<<(ostream&, Customer*);
	bool operator<(Customer*);
	bool operator>(Customer*);
        
    private:
        static int nextId;
	const int id;
        VehicleList vehicles;
};

#endif
